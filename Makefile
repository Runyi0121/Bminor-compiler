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

test_encoder: dirs $(TARGET)
	$(SHELL) runtest.sh encode

$(TARGET): $(OBJSDIR)/encoder.o $(OBJSDIR)/bminor.o
	$(CC) $(CFLAGS) $^ -lm -o $@

clean:
	rm -rf $(TARGET) $(OBJSDIR)

.PHONY: all clean test_encoder