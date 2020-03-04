#include "Help.h"

void Help_About(GtkWidget* widget, GtkWidget* window){
    GdkPixbuf *logo = gdk_pixbuf_new_from_file ("./Logo/Title.png", NULL);
    gtk_show_about_dialog(GTK_WINDOW(window), "program-name", "Made By TheAssembler1", 
                                              "version", "Version 1.0", 
                                              "logo", logo,  
                                              "website", "https://github.com/TheAssembler1/Cedit", 
                                              "website-label", "Source Code", 
                                               NULL);
}