#include <stdio.h>
#include <stdbool.h>
#include "board.h"

void board_init(struct sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            s->initial[i][j] = ' ';
            s->board[i][j] = ' ';
        }
    }
}

void board_clear(struct sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            s->board[i][j] = ' ';
        }
    }
}

void board_copy_initial(struct sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            s->board[i][j] = s->initial[i][j];
        }
    }
}

bool board_is_cell_free(const struct sudoku *s, int row, int col){
    if(s->board[row][col] == ' '){
        return true;
    }
    else {
        return false;
    }
}

bool board_is_full(const struct sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(s->board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

char board_get(const struct sudoku *s, int row, int col){
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE)
       ? s->board[row][col]
       : '?';
}

void board_set(struct sudoku *s, int row, int col, char value){
    s->board[row][col] = value;
}
