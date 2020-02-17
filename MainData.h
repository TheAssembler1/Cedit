#ifndef MAINDATA_H
#define MAINDATA_H
#include <gtk/gtk.h>

struct Main_Data{
    GtkWidget* window;
    GtkTextBuffer* current_text_buffer;
    GtkTextBuffer* line_numbers_buffer;
    gchar* current_selected_file;
};

#endif
