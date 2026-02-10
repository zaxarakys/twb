#include "twb.h"

void search_bar_setup (GtkWidget *search_bar) {
	gtk_widget_set_halign(search_bar, GTK_ALIGN_CENTER);
	gtk_widget_set_valign(search_bar, GTK_ALIGN_CENTER);

	gtk_entry_set_placeholder_text(GTK_ENTRY(search_bar), "Enter URL here...");
	gtk_widget_set_visible(search_bar, FALSE);
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
