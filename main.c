#include <gtk/gtk.h>
#include "Preferences/WindowSettings.h"

static void activate(GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *scrolled_window;
  GtkWidget *image;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), WINDOW_TITLE);
  gtk_window_set_default_size (GTK_WINDOW (window), WINDOW_WIDTH, WINDOW_HEIGHT);

  scrolled_window = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), WINDOW_BORDER);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);

  gtk_container_add (GTK_CONTAINER (window), scrolled_window);

  gtk_widget_show_all (window);
}



int main(int argc, char **argv){
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}