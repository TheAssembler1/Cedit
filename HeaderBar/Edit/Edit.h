#ifndef EDIT_H
#define EDIT_H
#include <gtk/gtk.h>

void Edit_Undo(GtkWidget* widget, gpointer data);

void Edit_Redo(GtkWidget* widget, gpointer data);

void Edit_Cut(GtkWidget* widget, gpointer data);

void Edit_Copy(GtkWidget* widget, gpointer data);

void Edit_Paste(GtkWidget* widget, gpointer data);

#endif