#ifndef EDIT_H
#define EDIT_H
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include "../../MainData.h"

void Edit_Undo(GtkWidget* widget, GtkSourceBuffer* text_buffer);

void Edit_Redo(GtkWidget* widget, GtkSourceBuffer* text_buffer);

void Edit_Cut(GtkWidget* widget, struct Main_Data* main_data);

void Edit_Copy(GtkWidget* widget, struct Main_Data* main_data);

void Edit_Paste(GtkWidget* widget, struct Main_Data* main_data);

#endif