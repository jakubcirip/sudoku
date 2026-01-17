#ifndef RENDER_H
#define RENDER_H

#include <stdbool.h>

// Render full board
void render_board(const struct sudoku *s);

// Render one cell - cell properties
void render_cell(char value, bool is_initial);

void render_message(const char *msg);

void render_prompt(const char *msg);

void render_error(const char *msg);

#endif