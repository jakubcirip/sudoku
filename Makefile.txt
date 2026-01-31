# flags
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -g

# targets
TARGET = sudoku_game
all: $(TARGET)

# source files
SRCS = board.c game.c render.c validation.c main.c
HDRS = board.h game.h render.h validation.h

# object files
OBJS = $(SRCS:.c=.o)

# compilation of output files
$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# compilation of object files
%.o: %.c $(HDRS)
		$(CC) $(CFLAGS) -c $< -o $@

#clean files
.PHONY: clean
clean:
		rm -f $(OBJS) $(TARGET)