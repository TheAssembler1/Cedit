#ifndef TOOLBARCALLBACKS_H
#define TOOLBARCALLBACKS_H
#include <gtk/gtk.h>
#include "../../MainData.h"
#include "../../HeaderBar/File/File.h"

void File_New_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void File_Open_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void File_Save_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

void File_Saveas_Toolbar(GtkWidget* widget, struct Main_Data* main_data);

#endif