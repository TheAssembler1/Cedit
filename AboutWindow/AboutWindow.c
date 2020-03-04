#include "AboutWindow.h"

void Create_About_Window(struct Main_Data* main_data){
    GtkWidget* about_window;

    about_window = gtk_about_dialog_new();

    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_window), "Cedit");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about_window), "Cedit");
}