#ifndef SEARCHBAR_H
#define SEARCHBAR_H

void search_bar_setup (GtkWidget *search_bar, GtkWidget *overlay);
void search_bar_action (GSimpleAction *action, GVariant *param, gpointer user_data);

#endif /* SEARCHBAR_H */
