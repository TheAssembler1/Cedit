#include "TextEnvironment.h"
#include <stdio.h>

void Create_Text_Environment(GtkWidget* scrolled_window){
    GtkWidget* text_view;
    GtkSourceBuffer* text_buffer;
    GtkSourceLanguage* c_language;
    GtkSourceLanguageManager* c_language_manager;

    c_language_manager = gtk_source_language_manager_get_default();

    c_language = gtk_source_language_manager_get_language(c_language_manager, "c");

    text_buffer = gtk_source_buffer_new_with_language(c_language);
    text_view = gtk_source_view_new_with_buffer(text_buffer);

    gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(text_view), TRUE);
    gtk_source_view_set_highlight_current_line(GTK_SOURCE_VIEW(text_view), TRUE);
    
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
}