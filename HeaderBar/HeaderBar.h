#ifndef HEADERBAR_H
#define HEADERBAR_H
#include <gtk/gtk.h>
#include "FileSubmenu/FileSubmenu.h"
#include "../MainData.h"

void Create_Header_Bar(struct Main_Data* main_data, GtkWidget** window_box);

#endif