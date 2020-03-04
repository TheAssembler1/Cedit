#gcc `pkg-config --cflags gtk+-3.0` -o Cedit main.c pkg-config`pkg-config --libs gtk+-3.0`
OBJS = Main.o  \
	   TextEnvironment/TextEnvironment.o \
	   HeaderBar/HeaderBar.o \
	   HeaderBar/File/File.o \
	   HeaderBar/Edit/Edit.o \
	   HeaderBar/Help/Help.o \
	   ToolBar/ToolBar.o	 \
	   ToolBar/ToolBarCallbacks/ToolBarCallbacks.o \
	   HeaderBar/Settings/Settings.o

LDFLAGS = `pkg-config --cflags gtk+-3.0` 
LDLIBS = `pkg-config --libs gtk+-3.0 gtksourceview-3.0` 

Cedit : $(OBJS)
	cc $(LDFLAGS) -o $@ $^ $(LDLIBS) 

Main.o : Main.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS) 

TextEnvironment/TextEnvironment.o : TextEnvironment/TextEnvironment.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS) 

LineNumbers/LineNumbers.o : LineNumbers/LineNumbers.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS) 

HeaderBar/HeaderBar.o : HeaderBar/HeaderBar.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

HeaderBar/File/File.o : HeaderBar/File/File.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

HeaderBar/Edit/Edit.o : HeaderBar/Edit/Edit.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

HeaderBar/Help/Help.o : HeaderBar/Help/Help.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

ToolBar/ToolBar.o : ToolBar/ToolBar.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

ToolBar/ToolBarCallbacks/ToolBarCallbacks.o : ToolBar/ToolBarCallbacks/ToolBarCallbacks.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

HeaderBar/Settings/Settings.o : HeaderBar/Settings/Settings.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

.PHONY : clean

clean :
	rm $(OBJS)