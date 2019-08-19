TARGET1	= libmod1.so
TARGET2 = libmod2.so
CC	= g++
CFLAGS	= -Wall -DLINUX
LDLIBS	=
OBJS1	= mod1.o
OBJS2	= mod2.o
SUBDIRS	= 

#include ../common/makefiles/dirs.mak

CFLAGS += -fPIC
LDFLAGS1 = -shared -Wl,-soname,$(TARGET1)
LDFLAGS2 = -shared -Wl,-soname,$(TARGET2)

ifdef RELEASE
CFLAGS += -O2
else
CFLAGS += -g -DDEBUG
endif

all:	main subdirs

main:	$(OBJS1) $(OBJS2) 
	$(CC) $(LDFLAGS1) -o $(TARGET1) $(OBJS1) $(LDLIBS1)
	$(CC) $(LDFLAGS2) -o $(TARGET2) $(OBJS2) $(LDLIBS2)
	cp $(TARGET1) $(TARGET2) ../
#ln -sf $(TARGET) $(TARGET).1

subdirs:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir; \
	done

mod1.o: \
	mod.h \
	mod1.cpp
	$(CC) $(CFLAGS) -c -o $*.o $*.cpp

mod2.o: \
	mod.h \
	mod2.cpp
	$(CC) $(CFLAGS) -c -o $*.o $*.cpp

clean:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done
	-rm -f $(OBJS1) $(OBJS2) *~ core $(TARGET1)* $(TARGET2)*
