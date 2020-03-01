#include "TextEnvironment.h"

void Create_Text_Environment(GtkWidget* scrolled_window){
    GtkWidget* text_view;
    GtkSourceBuffer* text_buffer;

    text_buffer = gtk_source_buffer_new(NULL);
    text_view = gtk_source_view_new_with_buffer (text_buffer);

    gtk_source_view_set_show_line_numbers(text_view, TRUE);

    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
}