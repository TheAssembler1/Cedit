#include "File.h"

void File_New(GtkWidget* widget, gpointer data){
    g_print("FILE NEW");
}

void File_Open(GtkWidget* widget, gpointer data){
    g_print("FILE OPEN");
}

void File_Save(GtkWidget* widget, gpointer data){
    g_print("FILE SAVE");
}

void File_Saveas(GtkWidget* widget, gpointer data){
    g_print("FILE SAVEAS");
}