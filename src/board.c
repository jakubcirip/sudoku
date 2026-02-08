#include "board.h"

void board_init(Sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            s->initial[i][j] = ' ';
            s->board[i][j] = ' ';
        }
    }
}

void board_clear(Sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            s->board[i][j] = '.';
            s->initial[i][j] = false;
        }
    }
}

void board_copy_initial(Sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
	    char v = s->board[i][j];
	    if(v != '.')
		s->initial[i][j] = true;
	    else
		s->initial[i][j] = false;
        }
    }
}

bool board_is_cell_free(const Sudoku *s, int row, int col){
    if(s->board[row][col] == ' '){
        return true;
    }
    else {
        return false;
    }
}

bool board_is_full(const Sudoku *s){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(s->board[i][j] == '.')
                return false;
        }
    }
    return true;
}

char board_get(const Sudoku *s, int row, int col){
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE)
       ? s->board[row][col]
       : '?';
}

void board_set(Sudoku *s, int row, int col, char value){
    s->board[row][col] = value;
}
