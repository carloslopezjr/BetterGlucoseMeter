CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = program
SRC = main.c functions.c
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c functions.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
