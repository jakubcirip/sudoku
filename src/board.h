#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

// Size of sudoku board
#define SIZE 9

// Sudoku struct
struct sudoku {
    char initial[SIZE][SIZE];
    char board[SIZE][SIZE];
};

// Initialization of game board
void board_init(struct sudoku *s);
void board_clear(struct sudoku *s);
void board_copy_initial(struct sudoku *s);

bool board_is_cell_free(const struct sudoku *s, int row, int col);
bool board_is_full(const struct sudoku *s);

char board_get(const struct sudoku *s, int row, int col);
void board_set(struct sudoku *s, int row, int col, char value);

#endif