TARGET	 = teste
CC	 = g++
CFLAGS	 = -Wall -DLINUX
INCLUDES = -I.. -I../../direxp
LDLIBS	 = -ldlib -L.. -ldirexp -L../../direxp -L../../format_string -lformat_string -ldl
OBJS	 = teste.o

ifdef RELEASE
CFLAGS += -O2
else
CFLAGS += -g -DDEBUG
endif

all:	mod $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDLIBS)

mod:
	cd modules/build && make

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $*.o $*.cpp

clean:
	cd modules/build && make clean
	-rm -f $(OBJS) *~ core $(TARGET) modules/*.so

exec:
	LD_LIBRARY_PATH=../:../../direxp:../../format_string ./$(TARGET)

leak_check:
	LD_LIBRARY_PATH=../:../../direxp:../../format_string valgrind --leak-check=yes --show-reachable=yes -v ./$(TARGET)

debug:
	LD_LIBRARY_PATH=../:../../direxp:../../format_string gdb ./$(TARGET)
