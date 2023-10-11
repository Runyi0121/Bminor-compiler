CC = gcc
CFLAGS = -std=gnu99 -g
SHELL = /bin/bash
SRCDIR = src
OBJSDIR = objs
TESTDIR = tests
INCDIR = inc
TARGET = bminor

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJSDIR)

$(OBJSDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(SRCDIR)/scanner.c: $(SRCDIR)/scanner.flex $(INCDIR)/token.h
	flex -o src/scanner.c src/scanner.flex

$(SRCDIR)/parser.c $(INCDIR)/parser.h: $(SRCDIR)/parser.bison
	bison -t --defines=inc/parser.h --output=src/parser.c -v src/parser.bison

test: dirs $(TARGET)
	$(SHELL) runtest.sh

$(TARGET): $(OBJSDIR)/encoder.o $(OBJSDIR)/bminor.o $(OBJSDIR)/library.o $(OBJSDIR)/scanner.o $(OBJSDIR)/parser.o $(OBJSDIR)/expr.o
	$(CC) $(CFLAGS) $^ -lm -o $@

clean:
	rm -rf $(TARGET) $(OBJSDIR)

.PHONY: all clean test_encoder