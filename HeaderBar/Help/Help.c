#include "Help.h"

void Help_About(GtkWidget* widget, struct Main_Data* main_data){
    gtk_show_about_dialog(GTK_WINDOW(main_data->window), NULL, NULL);
}