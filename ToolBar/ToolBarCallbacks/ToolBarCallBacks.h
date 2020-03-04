#ifndef TOOLBARCALLBACKS_H
#define TOOLBARCALLBACKS_H
#include <gtk/gtk.h>
#include "../../MainData.h"
#include "../../HeaderBar/File/File.h"
#include "../../HeaderBar/Edit/Edit.h"

void File_New_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void File_Open_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void File_Save_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void File_Saveas_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void Edit_Undo_Toolbar(GtkWidget* widget, GtkSourceBuffer* text_buffer);

void Edit_Redo_Toolbar(GtkWidget* widget, GtkSourceBuffer* text_buffer);

void Edit_Cut_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void Edit_Copy_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void Edit_Paste_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

#endif