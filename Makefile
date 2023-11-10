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

$(SRCDIR)/parser.c $(INCDIR)/parser.h: $(SRCDIR)/parser.bison
	bison --defines=inc/parser.h --output=src/parser.c -v src/parser.bison

$(SRCDIR)/scanner.c: $(SRCDIR)/scanner.flex $(INCDIR)/token.h
	flex -o src/scanner.c src/scanner.flex

test: dirs $(TARGET)
	$(SHELL) runtest.sh

$(TARGET): $(OBJSDIR)/parser.o $(OBJSDIR)/encoder.o $(OBJSDIR)/bminor.o $(OBJSDIR)/library.o $(OBJSDIR)/scanner.o $(OBJSDIR)/expr.o $(OBJSDIR)/decl.o $(OBJSDIR)/param_list.o $(OBJSDIR)/stmt.o $(OBJSDIR)/symbol.o $(OBJSDIR)/type.o $(OBJSDIR)/hash_table.o $(OBJSDIR)/scope.o  
	$(CC) $(CFLAGS) $^ -lm -o $@

clean:
	rm -rf $(TARGET) $(OBJSDIR) $(SRCDIR)/scanner.c $(SRCDIR)/parser.c $(SRCDIR)/parser.output $(INCDIR)/parser.h

.PHONY: all clean test_encoder