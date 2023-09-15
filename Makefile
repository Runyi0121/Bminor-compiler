CC = gcc
CFLAGS = -std=gnu99 -g
SHELL = /bin/bash
SRCDIR = src
OBJSDIR = objs
TESTDIR = tests
TARGET = bminor

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJSDIR)

$(OBJSDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(SRCDIR)/scanner.c: $(SRCDIR)/scanner.flex
	flex -o src/scanner.c src/scanner.flex

test: dirs $(TARGET)
	$(SHELL) runtest.sh


$(TARGET): $(OBJSDIR)/encoder.o $(OBJSDIR)/bminor.o $(OBJSDIR)/library.o $(OBJSDIR)/scanner.o
	$(CC) $(CFLAGS) $^ -lm -o $@

clean:
	rm -rf $(TARGET) $(OBJSDIR)

.PHONY: all clean test_encoder