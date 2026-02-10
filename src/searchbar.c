#include "twb.h"

void search_bar_action (GSimpleAction *action, GVariant *param, gpointer user_data) {
	GtkWidget* search_bar = (GtkWidget *) user_data;

	if(gtk_widget_get_visible(search_bar) == FALSE) {
		gtk_widget_set_visible(search_bar, TRUE);
		gtk_widget_grab_focus(search_bar);
	} else {
		gtk_widget_set_visible(search_bar, FALSE);
	}
}
