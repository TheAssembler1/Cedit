#ifndef FILE_H
#define FILE_H
#include <gtk/gtk.h>

void File_New(GtkWidget* widget, gpointer data);

void File_Open(GtkWidget* widget, gpointer data);

void File_Save(GtkWidget* widget, gpointer data);

void File_Saveas(GtkWidget* widget, gpointer data);

#endif