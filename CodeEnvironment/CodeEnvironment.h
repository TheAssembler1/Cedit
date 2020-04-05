#ifndef CODEENVIRONMENT_H
#define CODEENVIRONMENT_H
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>
#include <vte/vte.h>
#include "../MainData.h"
#include "../Preferences/TextSettings.h"
#include "../Preferences/WindowSettings.h"
#include "../Preferences/TerminalSettings.h"

void Create_Code_Environment(GtkWidget* sub_window_box, GtkWidget* scrolled_window, struct Main_Data* main_data, char **argv);

#endif