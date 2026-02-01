#ifndef VALIDATION_H
#define VALIDATION_H

#include "board.h"

// Row validation
bool validate_row(const Sudoku *s, int row);

// Column validation
bool validate_col(const Sudoku *s, int col);

// 3x3 blocks validation
bool validate_block(const Sudoku *s, int block_row, int block_col);

// full board validation
bool validate_board(const Sudoku *s);

// player next move validation
bool validate_move(const Sudoku *s, int row, int col, char value);

#endif
