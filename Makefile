TARGET	= libdlib.so
CC	= g++
CFLAGS	= -Wall -DLINUX
LDLIBS	=
OBJS	= dlib.o
SUBDIRS	= tests

INSTALL_DIR = usr/lib
INCLUDE_DIR = usr/include

CFLAGS += -fPIC
LDFLAGS = -shared -Wl,-soname,$(TARGET)

ifdef RELEASE
CFLAGS += -O2
else
CFLAGS += -g -DDEBUG
endif

all:	main subdirs

main:	$(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)
#ln -sf $(TARGET) $(TARGET).1

subdirs:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir; \
	done

dlib.o: \
	dlib.h \
	dlib.cpp
	$(CC) $(CFLAGS) -c -o $*.o $*.cpp

install:
	mkdir -p $(INSTALL_DIR)
	mkdir -p $(INCLUDE_DIR)
	cp -f $(TARGET) $(INSTALL_DIR)/$(TARGET)
	cp -f dlib.h $(INCLUDE_DIR)/dlib.h

install_debian:
	mkdir -p $(DESTDIR)/mlibs/$(INSTALL_DIR)
	mkdir -p $(DESTDIR)/mlibs-dev/$(INCLUDE_DIR)
	cp -f $(TARGET) $(DESTDIR)/mlibs/$(INSTALL_DIR)/$(TARGET)
	cp -f dlib.h $(DESTDIR)/mlibs-dev/$(INCLUDE_DIR)/dlib.h

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)
	rm -f $(INCLUDE_DIR)/dlib.h

clean:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done
	-rm -f $(OBJS) *~ core $(TARGET)*
