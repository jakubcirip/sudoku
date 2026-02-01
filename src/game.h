#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "validation.h"
#include "render.h"
#include <stdio.h>

// Game initialization
void game_init(Sudoku *s);

// Game loop
void game_loop(Sudoku *s);

// Input from player
bool game_input(int *row, int *col, char *value);

// Check if the cell is initial
bool game_is_initial(const Sudoku *s, int row, int col);

// Game move
void game_apply_move(Sudoku *s, int row, int col, char value);

// Check if the game is won
bool game_is_finished(const Sudoku *s);

#endif
