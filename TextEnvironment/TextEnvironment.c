#include "TextEnvironment.h"

void Create_Text_Environment(GtkWidget* window_box, struct Main_Data* main_data){
    GtkWidget* text_view;
    GtkWidget* scrolled_window;
    GtkWidget* scrolled_box;

    GtkWidget* seperator;
    
    GtkWidget* line_numbers_box;
    GtkWidget* line_numbers_view;

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_box_pack_start(GTK_BOX(window_box), scrolled_window, TRUE, TRUE, 0);
    scrolled_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(scrolled_window), scrolled_box);

    line_numbers_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(scrolled_box), line_numbers_box);
    line_numbers_view = gtk_text_view_new();
    main_data->line_numbers_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(line_numbers_view));
    gtk_text_buffer_set_text(main_data->line_numbers_buffer, "1", -1);
    gtk_text_view_set_editable((GtkTextView*)line_numbers_view, FALSE);
    gtk_text_view_set_cursor_visible((GtkTextView*)line_numbers_view, FALSE);

    text_view = gtk_text_view_new();
    main_data->current_text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(main_data->current_text_buffer, "", -1);

    seperator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    gtk_box_pack_start(GTK_BOX(scrolled_box), seperator, FALSE, FALSE, 4);

    gtk_box_pack_start(GTK_BOX(line_numbers_box), line_numbers_view, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(scrolled_box), text_view, TRUE, TRUE, 0);
}