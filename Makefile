#gcc `pkg-config --cflags gtk+-3.0` -o example-1 example-1.c `pkg-config --libs gtk+-3.0`

OBJS = main.o HeaderBar/HeaderBar.o HeaderBar/FileSubmenu/FileSubmenu.o TextEnvironment/TextEnvironment.o \
		SyntaxHighlighting/SyntaxHighlighting.o TextEnvironment/LineNumbers/LineNumbers.o

LDFLAGS = `pkg-config --cflags gtk+-3.0`
LDLIBS = `pkg-config --libs gtk+-3.0`

Cedit : $(OBJS)
	cc $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o : main.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

HeaderBar/HeaderBar.o : HeaderBar/HeaderBar.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

HeaderBar/FileSubmenu/FileSubmenu.o : HeaderBar/FileSubmenu/FileSubmenu.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

TextEnvironment/TextEnvironment.o : TextEnvironment/TextEnvironment.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)
	
SyntaxHighlighting/SyntaxHighlighting.o : SyntaxHighlighting/SyntaxHighlighting.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

TextEnvironment/LineNumbers/LineNumbers.o : TextEnvironment/LineNumbers/LineNumbers.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

.PHONE : clean

clean :
	rm $(OBJS)