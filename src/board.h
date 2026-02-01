#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

// Size of sudoku board
#define SIZE 9

// Sudoku struct
typedef struct {
    bool initial[SIZE][SIZE];
    char board[SIZE][SIZE];
} Sudoku;

// Initialization of game board
void board_init(Sudoku *s);
void board_clear(Sudoku *s);
void board_copy_initial(Sudoku *s);

bool board_is_cell_free(const Sudoku *s, int row, int col);
bool board_is_full(const Sudoku *s);

char board_get(const Sudoku *s, int row, int col);
void board_set(Sudoku *s, int row, int col, char value);

#endif
