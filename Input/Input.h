#ifndef INPUT_H
#define INPUT_H
#include <gtk/gtk.h>
#include "../HeaderBar/File/File.h"
#include "../MainData.h"

gboolean Keyboard_Input(GtkWidget *widget, GdkEventKey *event, struct Main_Data* main_data);

#endif