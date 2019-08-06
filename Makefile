CC = gcc
CFLAGS = -Wall

.PHONY:
all: webserver

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
