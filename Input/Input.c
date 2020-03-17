#include "Input.h"

gboolean Keyboard_Input(GtkWidget *widget, GdkEventKey *event, struct Main_Data* main_data){
     
    if(event->keyval == GDK_KEY_Control_L)
        File_Save(NULL, main_data);

    return FALSE;
}