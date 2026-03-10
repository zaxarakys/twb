#include "webview.h"
#include "gtk/gtk.h"
#include "twb.h"

static WebKitWebView *create_web_view(const gchar *url) {
	WebKitWebView *webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
	webkit_web_view_load_uri(webview, url);
	return webview;
}

static gboolean decide_policy_cb(WebKitWebView *wv, WebKitPolicyDecision *de, WebKitPolicyDecisionType ty, GtkWidget *entry){
	switch(ty) {
	case WEBKIT_POLICY_DECISION_TYPE_NAVIGATION_ACTION: {
		WebKitNavigationPolicyDecision *navigation_decision = WEBKIT_NAVIGATION_POLICY_DECISION(de);
		const gchar *redir_url = webkit_uri_request_get_uri(
				webkit_navigation_action_get_request(
				webkit_navigation_policy_decision_get_navigation_action(navigation_decision)
			));
		g_print("Redirecting to %s...\n", redir_url);
		gtk_editable_set_text(GTK_EDITABLE(entry), redir_url);
		break;
	}
	case WEBKIT_POLICY_DECISION_TYPE_NEW_WINDOW_ACTION: {
		WebKitNavigationPolicyDecision *navigation_decision = WEBKIT_NAVIGATION_POLICY_DECISION(de);
		g_print("Opening a new window...\n");
	}
	case WEBKIT_POLICY_DECISION_TYPE_RESPONSE:
		WebKitResponsePolicyDecision *response = WEBKIT_RESPONSE_POLICY_DECISION(de);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

twb_web_view *twb_web_view_new(const gchar *url) {
	twb_web_view *twv = malloc(sizeof(*twv));
	twv->box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	twv->webview = create_web_view(url);

	gtk_widget_set_hexpand(GTK_WIDGET(twv->webview), TRUE);
	gtk_widget_set_vexpand(GTK_WIDGET(twv->webview), TRUE);

	twv->bar = gtk_entry_new();

	g_signal_connect(GTK_WIDGET(twv->webview), "decide-policy", G_CALLBACK(decide_policy_cb), twv->bar);

	/* gtk_editable_set_text(GTK_EDITABLE(twv->bar), url); */

	gtk_box_append(GTK_BOX(twv->box), twv->bar);
	gtk_box_append(GTK_BOX(twv->box), GTK_WIDGET(twv->webview));
  return twv;
}
