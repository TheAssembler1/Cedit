#ifndef TOOLBAR_H
#define TOOLBAR_H
#include <gtk/gtk.h>
#include "ToolBarCallbacks/ToolBarCallBacks.h"
#include "../MainData.h"

void Create_Tool_Bar(struct Main_Data* main_data, GtkAccelGroup* accel_group);

#endif