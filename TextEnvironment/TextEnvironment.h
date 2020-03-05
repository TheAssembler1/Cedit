#ifndef TEXTENVIRONMENT_H
#define TEXTENVIRONMENT_H
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include <vte/vte.h>
#include "../MainData.h"
#include "../Preferences/TextSettings.h"

void Create_Text_Environment(GtkWidget* sub_window_box, GtkWidget* scrolled_window, struct Main_Data* main_data, char **argv);

#endif