#include "Edit.h"

void Edit_Redo(GtkWidget* widget, GtkSourceBuffer* text_buffer){
    if(gtk_source_buffer_can_redo(text_buffer))
        gtk_source_buffer_redo(text_buffer);
}

void Edit_Cut(GtkWidget* widget, gpointer data){
    g_print("EDIT CUT\n");
}

void Edit_Copy(GtkWidget* widget, gpointer data){
    g_print("EDIT COPY\n");
}

void Edit_Paste(GtkWidget* widget, gpointer data){
    g_print("EDIT PASTE\n");
}