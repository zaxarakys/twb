#include "twb.h"
#include "webview.h"

static void search_bar_enter (GtkEntry *search_bar, gpointer user_data) {
	const gchar *url = gtk_editable_get_text(GTK_EDITABLE(search_bar));
	GtkWidget *overlay = GTK_WIDGET(user_data);

	g_print("Loading: %s\n", url);
	gtk_widget_set_visible(GTK_WIDGET(search_bar), FALSE);

	twb_web_view *twv = twb_web_view_new(url);
	gtk_overlay_set_child(GTK_OVERLAY(overlay), GTK_WIDGET(twv->box));
	gtk_widget_grab_focus(GTK_WIDGET(twv->webview));
}


void search_bar_setup (GtkWidget *search_bar, GtkWidget *overlay) {
	gtk_widget_set_halign(search_bar, GTK_ALIGN_CENTER);
	gtk_widget_set_valign(search_bar, GTK_ALIGN_CENTER);

	gtk_entry_set_placeholder_text(GTK_ENTRY(search_bar), "Enter URL here...");
	gtk_widget_set_visible(search_bar, FALSE);

	g_signal_connect(search_bar, "activate", G_CALLBACK(search_bar_enter), overlay);
}

void search_bar_action (GSimpleAction *action, GVariant *param, gpointer user_data) {
	GtkWidget* search_bar = (GtkWidget *) user_data;

	if(gtk_widget_get_visible(search_bar) == FALSE) {
		gtk_widget_set_visible(search_bar, TRUE);
		gtk_widget_grab_focus(search_bar);
	} else {
		gtk_widget_set_visible(search_bar, FALSE);
	}
}
