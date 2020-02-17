#include "TextEnvironment.h"

void Create_Text_Environment(GtkWidget* window_box, struct Main_Data* main_data){
    GtkWidget* text_view;
    GtkWidget* scrolled_window;
    GtkWidget* scrolled_box;

    text_view = gtk_text_view_new();
    main_data->current_text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    gtk_text_buffer_set_text(main_data->current_text_buffer, "", -1);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_box_pack_start(GTK_BOX(window_box), scrolled_window, TRUE, TRUE, 0);

    scrolled_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(scrolled_window), scrolled_box);

    gtk_box_pack_start(GTK_BOX(scrolled_box), text_view, TRUE, TRUE, 0);
}