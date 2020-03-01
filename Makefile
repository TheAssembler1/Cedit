#gcc `pkg-config --cflags gtk+-3.0` -o Cedit main.c pkg-config`pkg-config --libs gtk+-3.0`
OBJS = main.o  \
	   TextEnvironment/TextEnvironment.o \

LDFLAGS = `pkg-config --cflags gtk+-3.0` 
LDLIBSGTK = `pkg-config --libs gtk+-3.0 gtksourceview-3.0` 

Cedit : $(OBJS)
	cc $(LDFLAGS) -o $@ $^ $(LDLIBSGTK) 

main.o : main.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBSGTK) 

TextEnvironment/TextEnvironment.o : TextEnvironment/TextEnvironment.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBSGTK) 

LineNumbers/LineNumbers.o : LineNumbers/LineNumbers.c
	cc $(LDFLAGS) -o $@ -c $^ $(LDLIBSGTK) 

.PHONY : clean

clean :
	rm $(OBJS)