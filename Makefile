CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
LDFLAGS = -L/usr/local/lib -lSDL3 -lm
TARGET = main
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
