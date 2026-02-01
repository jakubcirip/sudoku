#ifndef RENDER_H
#define RENDER_H

#include <stdbool.h>
#include "board.h"

// Render full board
void render_board(const Sudoku *s);

// Render one cell - cell properties
void render_cell(char value, bool is_initial);

void render_message(const char *msg);

void render_prompt(const char *msg);

void render_error(const char *msg);

#endif
