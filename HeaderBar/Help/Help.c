#include "Help.h"

void Help_About(GtkWidget* widget, GtkWidget* window){
    GdkPixbuf *logo = gdk_pixbuf_new_from_file (LOGO_TITLE, NULL);
    gtk_show_about_dialog(GTK_WINDOW(window), "program-name", AUTHOR, 
                                              "version", VERSION, 
                                              "logo", logo,  
                                              "website", WEBSITE, 
                                              "website-label", WEBSITE_LABEL, 
                                               NULL);
}