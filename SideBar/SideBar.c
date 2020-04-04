#include "SideBar.h"

static void Open_Location(GtkPlacesSidebar* sidebar, GObject* location, GtkPlacesOpenFlags open_flags, gpointer user_data);
static int IsDirectory(const char* file_path);

void Create_Side_Bar(GtkWidget* sub_window_box){
    GtkWidget* side_bar;

    side_bar = gtk_places_sidebar_new();

    gtk_places_sidebar_set_show_desktop(GTK_PLACES_SIDEBAR(side_bar), TRUE);

    gtk_box_pack_start(GTK_BOX(sub_window_box), side_bar, FALSE, FALSE, 0);
    gtk_widget_set_hexpand(side_bar, FALSE);

    g_signal_connect(side_bar, "open-location", G_CALLBACK(Open_Location), NULL);
}

static void Open_Location(GtkPlacesSidebar* sidebar, GObject* location, GtkPlacesOpenFlags open_flags, gpointer user_data){
    const char* file_path = g_file_get_path(G_FILE(location));
    GFile* new_file = g_file_new_for_path(file_path);
    gtk_places_sidebar_set_location(sidebar, G_FILE(new_file));
}

static int IsDirectory(const char* file_path){
   struct stat statbuf;

   if (stat(file_path, &statbuf) != 0)
       return 0;

   return S_ISDIR(statbuf.st_mode);
}