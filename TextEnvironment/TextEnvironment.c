#include "TextEnvironment.h"

void Create_Text_Environment(GtkWidget* scrolled_window){
    GtkWidget* text_view;
    GtkTextBuffer* text_buffer;

    text_view = gtk_text_view_new();
    text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text (text_buffer, "", -1);
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
}