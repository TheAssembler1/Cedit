#ifndef MAINDATA_H
#define MAINDATA_H
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>

struct Main_Data{
    GtkWidget* window;
    GtkSourceBuffer* text_buffer;
    GtkSourceFile* source_file;
    GtkClipboard* clipboard;
    GtkWidget* about_window;
    GtkWidget* window_box;
};

#endif