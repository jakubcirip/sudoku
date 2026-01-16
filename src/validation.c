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
bool validate_block(const struct sudoku *s, int block_row, int block_col){
    int start_row = block_row * 3;
    int start_col = block_col * 3;
    int seen[10] = {0};
    for(int i=start_row; i<start_row+3; i++){
        for(int j=start_col; j<start_col+3; j++){
            char c = board_get(s, i, j);
            if(c == ' '){
            continue;
            }
            int num = c - '0';
            seen[num]++;
            if(seen[num]>1){
                return false;
            }
        }
    }
    return true;
}

// full board validation
bool validate_board(const struct sudoku *s){
    for(int i=0; i<SIZE; i++){
        if(!validate_row(s, i))
            return false;
    }
    for(int j=0; j<SIZE; j++){
        if(!validate_col(s, j))
            return false;
    }
    for(int bi=0; bi<3; bi++){
        for(int bj=0; bj<3; bj++){
            if(!validate_block(s, bi, bj))
                return false;
        }
    }
    return true;
}

// player next move validation
bool validate_move(const struct sudoku *s, int row, int col, char value){
    if(value < '1' || value > '9')
        return false;
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return false;
    char old = board_get(s, row, col);
    board_set(s, row, col, value);
    bool ok = validate_row(s, row) && validate_col(s, col) && validate_block(s, row/3, col/3);
    board_set(s, row, col, old);
    return  ok;
}
