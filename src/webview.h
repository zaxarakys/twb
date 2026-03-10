#ifndef WEBVIEW_H
#define WEBVIEW_H

typedef struct  {
	GtkBox *box;
	GtkWidget *bar;
	WebKitWebView *webview;
} twb_web_view; 

WebKitWebView *create_web_view(const gchar *url);

#endif /* WEBVIEW_H */
