#include <unistd.h>
#include "webview.h"
#include "gtk/gtk.h"
#include "twb.h"

static WebKitWebView *create_web_view(const gchar *url) {
	WebKitWebContext *context = webkit_web_context_new();
	
	/* Adding pulse and pipewire paths to sandbox so sound works */
	gchar *pulse_path = g_strdup_printf("/run/user/%u/pulse", (unsigned int)getuid());
	gchar *pipewire_path = g_strdup_printf("/run/user/%u/pipewire-0", (unsigned int)getuid());

	webkit_web_context_add_path_to_sandbox(context, pulse_path, TRUE);
	webkit_web_context_add_path_to_sandbox(context, pipewire_path, TRUE);

	g_free(pulse_path);
	g_free(pipewire_path);

	WebKitWebView *webview =
		WEBKIT_WEB_VIEW(
			g_object_new(WEBKIT_TYPE_WEB_VIEW, "web-context", context, NULL)
		);

	/*
	 * Unref context because refcount is 2 from webkit_web_context_new and
	 * g_object_new
	 */
	g_object_unref(context);

	webkit_web_view_load_uri(webview, url);
	return webview;
}

static gboolean decide_policy_cb(WebKitWebView *wv, WebKitPolicyDecision *de, WebKitPolicyDecisionType ty, GtkWidget *entry){
	switch(ty) {
	case WEBKIT_POLICY_DECISION_TYPE_NAVIGATION_ACTION: {
		/* WebKitNavigationPolicyDecision *navigation_decision = WEBKIT_NAVIGATION_POLICY_DECISION(de); */
		g_print("Redirecting...\n");
		break;
	}
	case WEBKIT_POLICY_DECISION_TYPE_NEW_WINDOW_ACTION: {
		/* WebKitNavigationPolicyDecision *navigation_decision = WEBKIT_NAVIGATION_POLICY_DECISION(de); */
		g_print("Opening a new window...\n");
		/* TODO: IMPLEMENT */
		break;
	}
	case WEBKIT_POLICY_DECISION_TYPE_RESPONSE:
		/* WebKitResponsePolicyDecision *response = WEBKIT_RESPONSE_POLICY_DECISION(de); */
		/* TODO: IMPLEMENT */
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

static gboolean redirect_cb(WebKitWebView *wv, GParamSpec *pspec, GtkEntry *entry){
	g_print("Loaded %s\n", webkit_web_view_get_uri(wv));
	gtk_editable_set_text(GTK_EDITABLE(entry), webkit_web_view_get_uri(wv));
	return TRUE;
}

static gboolean url_bar_activate_cb(GtkEntry *entry, WebKitWebView *wv){
	const gchar *redir_url = gtk_editable_get_text(GTK_EDITABLE(entry));
	webkit_web_view_load_uri(wv, redir_url);
	gtk_widget_grab_focus(GTK_WIDGET(wv));
	return TRUE;
}

twb_web_view *twb_web_view_new(const gchar *url) {
	twb_web_view *twv = malloc(sizeof(*twv));
	twv->box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	twv->webview = create_web_view(url);

	gtk_widget_set_hexpand(GTK_WIDGET(twv->webview), TRUE);
	gtk_widget_set_vexpand(GTK_WIDGET(twv->webview), TRUE);

	twv->bar = gtk_entry_new();

	gtk_editable_set_text(GTK_EDITABLE(twv->bar), url);

	g_signal_connect(GTK_WIDGET(twv->webview), "decide-policy", G_CALLBACK(decide_policy_cb), twv->bar);
	g_signal_connect(GTK_WIDGET(twv->bar), "activate", G_CALLBACK(url_bar_activate_cb), twv->webview);
	g_signal_connect(GTK_WIDGET(twv->webview), "notify::uri", G_CALLBACK(redirect_cb), twv->bar);


	gtk_box_append(GTK_BOX(twv->box), twv->bar);
	gtk_box_append(GTK_BOX(twv->box), GTK_WIDGET(twv->webview));
  return twv;
}
