#ifndef TWB_H
#define TWB_H

#include <gtk/gtk.h>
#include <webkit/webkit.h>
#include "config.h"

void search_bar_setup (GtkWidget *search_bar, GtkWidget *overlay);
void search_bar_action (GSimpleAction *action, GVariant *param, gpointer user_data);
WebKitWebView *create_web_view(const gchar *url);

#endif /* TWB_H */
