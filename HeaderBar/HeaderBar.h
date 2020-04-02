
#ifndef HEADERBAR_H
#define HEADERBAR_H
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include "../MainData.h"
#include "File/File.h"
#include "Edit/Edit.h"
#include "Help/Help.h"
#include "Settings/Settings.h"
#include <gdkkeysyms.h>

GtkWidget* Create_Header_Bar(struct Main_Data* main_data);

#endif