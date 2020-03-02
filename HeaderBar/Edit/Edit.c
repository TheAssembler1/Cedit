#include "Edit.h"

void Edit_Undo(GtkWidget* widget, gpointer data){
    g_print("EDIT UNDO\n");
}

void Edit_Redo(GtkWidget* widget, gpointer data){
    g_print("EDIT REDO\n");
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