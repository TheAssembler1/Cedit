#gcc `pkg-config --cflags gtk+-3.0` -o Cedit main.c pkg-config`pkg-config --libs gtk+-3.0`
OBJS = main.o  \
	   TextEnvironment/TextEnvironment.o \
	   HeaderBar/HeaderBar.o \
	   HeaderBar/File/File.o

LDFLAGS = `pkg-config --cflags gtk+-3.0` 
LDLIBS = `pkg-config --libs gtk+-3.0 gtksourceview-3.0` 

Cedit : $(OBJS)
	cc $(LDFLAGS) -o $@ $^ $(LDLIBS) 

main.o : main.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS) 

TextEnvironment/TextEnvironment.o : TextEnvironment/TextEnvironment.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS) 

LineNumbers/LineNumbers.o : LineNumbers/LineNumbers.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS) 

HeaderBar/HeaderBar.o : HeaderBar/HeaderBar.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

HeaderBar/File/File.o : HeaderBar/File/File.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBS)

.PHONY : clean

clean :
	rm $(OBJS)