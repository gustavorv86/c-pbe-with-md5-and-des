SHELL:=/bin/bash

########## DIRECTORIES ##########

SRCDIR:=src

BUILDDIR:=build

DISTDIR:=dist

TARGET_LIB:=$(DISTDIR)/libpbemd5des.so

TARGET_TEST:=$(DISTDIR)/pbe_md5_des_test_main

BUILDOBJS:=$(BUILDDIR)/pbe_md5_des.o

########## COMPILER AND LINKER ############

CC:=/usr/bin/gcc

CFLAGS:=-ggdb -Wall -Wextra -I$(SRCDIR)/pbe_md5_des

LDFLAGS:=-lssl

########## RULES ##########

all: start make_dirs $(TARGET_LIB) $(TARGET_TEST) end

lib: start make_dirs $(TARGET_LIB) end

make_dirs:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(DISTDIR)

clean: 
	@echo "Cleaning..."
	@rm -rf $(BUILDDIR)
	@rm -rf $(DISTDIR)
	@echo "Done"

start:
	@echo "Compiling..."

$(BUILDDIR)/pbe_md5_des.o: $(SRCDIR)/pbe_md5_des/pbe_md5_des.h $(SRCDIR)/pbe_md5_des/pbe_md5_des.c
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/pbe_md5_des/pbe_md5_des.c -o $(BUILDDIR)/pbe_md5_des.o

$(BUILDDIR)/pbe_md5_des_test_main.o: $(SRCDIR)/test/pbe_md5_des_test_main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/test/pbe_md5_des_test_main.c -o $(BUILDDIR)/pbe_md5_des_test_main.o

$(TARGET_LIB): $(BUILDDIR)/pbe_md5_des.o
	$(CC) -shared -o $(TARGET_LIB) $(BUILDDIR)/pbe_md5_des.o

$(TARGET_TEST): $(TARGET_LIB) $(BUILDDIR)/pbe_md5_des_test_main.o
	$(CC) $(CFLAGS) -L$(DISTDIR) $(BUILDDIR)/pbe_md5_des_test_main.o -o $(TARGET_TEST) $(LDFLAGS) -lpbemd5des
	
end:
	@echo "Done..."
