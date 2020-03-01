#include "TextEnvironment.h"

void Create_Text_Environment(GtkWidget* window_box, GtkWidget* scrolled_window, GtkSourceBuffer** text_buffer){
    GtkWidget* scrolled_window_box;
    GtkWidget* text_view;
    GtkSourceLanguage* c_language;
    GtkSourceLanguageManager* c_language_manager;

    c_language_manager = gtk_source_language_manager_get_default();
    c_language = gtk_source_language_manager_get_language(c_language_manager, "c");

    *text_buffer = gtk_source_buffer_new_with_language(c_language);
    text_view = gtk_source_view_new_with_buffer(*text_buffer);

    gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(text_view), TRUE);
    gtk_source_view_set_highlight_current_line(GTK_SOURCE_VIEW(text_view), TRUE);
    gtk_source_view_set_auto_indent(GTK_SOURCE_VIEW(text_view), TRUE);

    gtk_box_pack_start(GTK_BOX(window_box), scrolled_window, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
}