
#ifndef HEADERBAR_H
#define HEADERBAR_H
#include <gtk/gtk.h>
#include "File/File.h"
#include "Edit/Edit.h"
#include "Help/Help.h"

GtkWidget* Create_Header_Bar(GtkWidget* window, GtkSourceBuffer* text_buffer);

#endif