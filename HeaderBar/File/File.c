#include "File.h"

void File_New(GtkWidget* widget, gpointer data){
    g_print("FILE NEW\n");
}

void File_Open(GtkWidget* widget, gpointer data){
    g_print("FILE OPEN\n");
}

void File_Save(GtkWidget* widget, gpointer data){
    g_print("FILE SAVE\n");
}

void File_Saveas(GtkWidget* widget, gpointer data){
    g_print("FILE SAVEAS\n");
}