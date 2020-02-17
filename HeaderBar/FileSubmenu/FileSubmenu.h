#ifndef FILESUBMENU_H
#define FILESUBMENU_H
#include <gtk/gtk.h>
#include "../../MainData.h"

void File_New(GtkWidget* widget, struct Main_Data* main_data);

void File_Open(GtkWidget* widget, struct Main_Data* main_data);

void File_Save(GtkWidget* widget, struct Main_Data* main_data);

void File_Saveas(GtkWidget* widget, struct Main_Data* main_data);

#endif