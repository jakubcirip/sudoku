#include "validation.h"

bool validate_row(const struct sudoku *s, int row){
    int seen[10] = {0};
    for(int i=0; i<SIZE; i++){
        char c = board_get(s, row, i);
        if(c == ' '){
            continue;
        }
        int num = c - '0';
        seen[num]++;
        if(seen[num]>1){
            return false;
        }
    }
    return true;
}

// Column validation
bool validate_col(const struct sudoku *s, int col){
    int seen[10] = {0};
    for(int i=0; i<SIZE; i++){
        char c = board_get(s, i, col);
        if(c == ' '){
            continue;
        }
        int num = c - '0';
        seen[num]++;
        if(seen[num]>1){
            return false;
        }
    }
    return true;
}

// 3x3 blocks validation
bool validate_block(const struct sudoku *s, int block_row, int block_col);

// full board validation
bool validate_board(const struct sudoku *s);

// player next move validation
bool validate_move(const struct sudoku *s, int row, int col, char value);
