#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include "Preferences/WindowSettings.h"
#include "TextEnvironment/TextEnvironment.h"
#include "HeaderBar/HeaderBar.h"
#include "ToolBar/ToolBar.h"
#include "SideBar/SideBar.h"
#include "MainData.h"

struct Main_Data main_data;

static void Activate(GtkApplication *app, char **argv){
  GtkWidget* scrolled_window;
  GtkWidget* sub_window_box;

  main_data.window = gtk_application_window_new(app);
  GdkPixbuf* letter_logo = gdk_pixbuf_new_from_file (WINDOW_LETTER_LOGO, NULL);
  gtk_window_set_icon(GTK_WINDOW(main_data.window), letter_logo);
  gtk_window_set_title (GTK_WINDOW(main_data.window), WINDOW_TITLE);
  gtk_window_set_default_size (GTK_WINDOW(main_data.window), WINDOW_WIDTH, WINDOW_HEIGHT);

  scrolled_window = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_set_border_width(GTK_CONTAINER(scrolled_window), WINDOW_BORDER);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_window_set_position(GTK_WINDOW(main_data.window), GTK_WIN_POS_CENTER_ALWAYS);

  main_data.text_buffer = gtk_source_buffer_new(NULL);
  main_data.about_window = gtk_about_dialog_new();
  
  Create_Header_Bar(&main_data);
  Create_Tool_Bar(&main_data);

  sub_window_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_pack_start(GTK_BOX(main_data.window_box), sub_window_box, TRUE, TRUE, 0);

  Create_Side_Bar(sub_window_box);
  Create_Text_Environment(sub_window_box, scrolled_window, &main_data, argv); 

  gtk_widget_show_all(main_data.window);
}



int main(int argc, char **argv){
  main_data.text_buffer = NULL;
  main_data.window = NULL;
  main_data.source_file = gtk_source_file_new();

  GtkApplication *app;
  int status;

  app = gtk_application_new(WINDOW_ID, G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(Activate), argv);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
