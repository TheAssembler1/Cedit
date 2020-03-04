#include "ToolBarCallBacks.h"

void File_New_Toolbar(GtkWidget* widget, struct Main_Data* main_data){
    File_New(NULL, main_data);
}

void File_Open_Toolbar(GtkWidget* widget, struct Main_Data* main_data){
    File_Open(NULL, main_data);
}

void File_Save_Toolbar(GtkWidget* widget, struct Main_Data* main_data){
    File_Save(NULL, main_data);
}

void File_Saveas_Toolbar(GtkWidget* widget, struct Main_Data* main_data){
    File_Saveas(NULL, main_data);
}