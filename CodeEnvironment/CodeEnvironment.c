#include "CodeEnvironment.h"

static void Create_Terminal(GtkWidget* scrolled_window, GtkWidget* sub_window_box);
static void Create_Source_Map(GtkWidget* sub_window_box, GtkSourceView* text_view);
static GtkClipboard* Get_Clipboard();

void Create_Code_Environment(GtkWidget* sub_window_box, GtkWidget* scrolled_window, struct Main_Data* main_data, char **argv){
    GtkWidget* text_view;
    GtkSourceLanguage* c_language;
    GtkSourceLanguageManager* c_language_manager;
    GtkSourceStyleSchemeManager* theme_language_manager;
    GtkSourceStyleScheme* text_scheme;

    c_language_manager = gtk_source_language_manager_get_default();
    c_language = gtk_source_language_manager_get_language(c_language_manager, DEFAULT_LANGUAGE);

    gtk_source_buffer_set_language(GTK_SOURCE_BUFFER(main_data->text_buffer), c_language);
    text_view = gtk_source_view_new_with_buffer(main_data->text_buffer);

    gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(text_view), TRUE);
    gtk_source_view_set_highlight_current_line(GTK_SOURCE_VIEW(text_view), TRUE);
    gtk_source_view_set_auto_indent(GTK_SOURCE_VIEW(text_view), TRUE);

    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    Create_Terminal(scrolled_window, sub_window_box);
    Create_Source_Map(sub_window_box, GTK_SOURCE_VIEW(text_view));

    theme_language_manager = gtk_source_style_scheme_manager_new();
    text_scheme = gtk_source_style_scheme_manager_get_scheme(theme_language_manager, DEFAULT_THEME);

    gtk_source_buffer_set_style_scheme(main_data->text_buffer, text_scheme);

    main_data->clipboard = Get_Clipboard();
}

static void Create_Terminal(GtkWidget* scrolled_window, GtkWidget* sub_window_box){
    GtkWidget* text_terminal_box;
    GtkWidget* terminal;
    gchar **envp;
    gchar **command;

    text_terminal_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_box_pack_start(GTK_BOX(sub_window_box), text_terminal_box, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(text_terminal_box), scrolled_window, TRUE, TRUE, 0);

    terminal = vte_terminal_new();
    envp = g_get_environ();
    command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    g_strfreev(envp);
    vte_terminal_spawn_async(VTE_TERMINAL(terminal),
        VTE_PTY_DEFAULT,
        NULL,       /* working directory  */
        command,    /* command */
        NULL,       /* environment */
        0,          /* spawn flags */
        NULL, NULL, /* child setup */
        NULL,       /* child pid */
        -1,         /* timeout */
        NULL, NULL, NULL);
    vte_terminal_set_size(VTE_TERMINAL(terminal), 1, 5);
    gtk_box_pack_start(GTK_BOX(text_terminal_box), terminal, FALSE, FALSE, 0);
}

static void Create_Source_Map(GtkWidget* sub_window_box, GtkSourceView* text_view){
    GtkWidget* source_map;

    source_map = gtk_source_map_new();
    gtk_source_map_set_view(GTK_SOURCE_MAP(source_map), GTK_SOURCE_VIEW(text_view));
    gtk_box_pack_start(GTK_BOX(sub_window_box), source_map, FALSE, FALSE, 0);
}

static GtkClipboard* Get_Clipboard(){
    GdkDisplay* display;

    display = gdk_display_get_default();
    return gtk_clipboard_get_default(display);
}
