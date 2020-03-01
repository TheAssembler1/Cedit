#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include "Preferences/WindowSettings.h"
#include "TextEnvironment/TextEnvironment.h"
#include "HeaderBar/HeaderBar.h"

static void Activate(GtkApplication *app, gpointer user_data){
  GtkWidget* window;
  GtkWidget* window_box;
  GtkWidget* scrolled_window;
  GtkSourceBuffer* text_buffer;
  GtkWidget* text_view;

  window = gtk_application_window_new(app);
  gtk_window_set_title (GTK_WINDOW(window), WINDOW_TITLE);
  gtk_window_set_default_size (GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);

  scrolled_window = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_set_border_width(GTK_CONTAINER(scrolled_window), WINDOW_BORDER);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);

  window_box = Create_Header_Bar(window, *text_buffer);
  Create_Text_Environment(window_box, scrolled_window, &text_buffer);

  gtk_widget_show_all (window);
}



int main(int argc, char **argv){
  GtkApplication *app;
  int status;

  app = gtk_application_new(WINDOW_ID, G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(Activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}