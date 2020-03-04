#include "SideBar.h"

void Create_Side_Bar(GtkWidget* sub_window_box){
    GtkWidget* side_bar;

    side_bar = gtk_places_sidebar_new();

    gtk_box_pack_start(GTK_BOX(sub_window_box), side_bar, TRUE, TRUE, 0);
}