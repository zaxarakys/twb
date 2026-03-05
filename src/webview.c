#include "twb.h"

WebKitWebView *create_web_view(const gchar *url) {
	WebKitWebView *webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
	webkit_web_view_load_uri(webview, url);
	return webview;
}
