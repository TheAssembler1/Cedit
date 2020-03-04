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

void Edit_Undo_Toolbar(GtkWidget* widget, GtkSourceBuffer* text_buffer){
    Edit_Undo(NULL, text_buffer);
}

void Edit_Redo_Toolbar(GtkWidget* widget, GtkSourceBuffer* text_buffer){
    Edit_Redo(NULL, text_buffer);
}

void Edit_Cut_Toolbar(GtkWidget* widget, struct Main_Data* main_data){
    Edit_Cut(NULL, main_data);
}

void Edit_Copy_Toolbar(GtkWidget* widget, struct Main_Data* main_data){
    Edit_Copy(NULL, main_data);
}

void Edit_Paste_Toolbar(GtkWidget* widget, struct Main_Data* main_data){
    Edit_Paste(NULL, main_data);
}