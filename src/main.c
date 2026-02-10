#include "twb.h"

static void setup_actions(GtkWindow *win, GtkWidget *widget) {
	GSimpleAction *search_action = g_simple_action_new("search", NULL); /* Search bar action */

	g_signal_connect(search_action, "activate", G_CALLBACK(search_bar_action), NULL); /* Search bar action TODO: not use null */
	g_action_map_add_action(G_ACTION_MAP(win), G_ACTION(search_action));
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "Window");
	gtk_window_set_default_size(GTK_WINDOW (window), 1280, 1024);
	gtk_window_present(GTK_WINDOW (window));

	GtkWidget *parent_overlay = gtk_overlay_new();

	gtk_window_set_child(GTK_WINDOW(window), parent_overlay);
	gtk_window_present(GTK_WINDOW(window));

	setup_actions(GTK_WINDOW(window), NULL); /* TODO: not use null */

	/* TODO: make keycombo depend on config */
	const char *accels[] = {"<Alt>s", NULL}; /* Search bar action */
	gtk_application_set_accels_for_action(GTK_APPLICATION(app), "win.search", accels);
}

int main(int argc, char *argv[]) {
	GtkApplication *app;
	int status;

	app = gtk_application_new("com.zaxarakys.twb", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
