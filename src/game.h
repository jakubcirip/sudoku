#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "validation.h"
#include "render.h"

// Game initialization
void game_init(struct sudoku *s);

// Game loop
void game_loop(struct sudoku *s);

// Input from player
bool game_input(int *row, int *col, char *value);

// Check if the cell is initial
bool game_is_initial(const struct sudoku *s, int row, int col);

// Game move
void game_apply_move(struct sudoku *s, int row, int col, char value);

// Check if the game is won
bool game_is_finished(const struct sudoku *s);

#endif