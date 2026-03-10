#include "webview.h"
#include "gtk/gtk.h"
#include "twb.h"

static WebKitWebView *create_web_view(const gchar *url) {
	WebKitWebView *webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
	webkit_web_view_load_uri(webview, url);
	return webview;
}

twb_web_view *twb_web_view_new(const gchar *url) {
	twb_web_view *twv = malloc(sizeof(*twv));
	twv->box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	twv->webview = create_web_view(url);

	gtk_widget_set_hexpand(GTK_WIDGET(twv->webview), TRUE);
	gtk_widget_set_vexpand(GTK_WIDGET(twv->webview), TRUE);

	twv->bar = gtk_entry_new();

	gtk_editable_set_text(GTK_EDITABLE(twv->bar), url);

	gtk_box_append(GTK_BOX(twv->box), twv->bar);
	gtk_box_append(GTK_BOX(twv->box), GTK_WIDGET(twv->webview));
  return twv;
}
