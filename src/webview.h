#ifndef WEBVIEW_H
#define WEBVIEW_H

/*
 * Use forward declarations to make header file self-contained and suppress
 * clang warngings and errors. Since the struct only holds pointers to those
 * types it will work. gchar still needs to be included from glib.h.
 */
#include <glib.h>
typedef struct _GtkBox GtkBox;
typedef struct _GtkWidget GtkWidget;
typedef struct _WebKitWebView WebKitWebView;

typedef struct  {
	GtkBox *box;
	GtkWidget *bar;
	WebKitWebView *webview;
} twb_web_view; 

WebKitWebView *create_web_view(const gchar *url);

#endif /* WEBVIEW_H */
