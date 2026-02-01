#include "render.h"
#include "board.h"
#include <stdio.h>

void render_board(const Sudoku *s){
    printf("  1 2 3 | 4 5 6 | 7 8 9  \n");
    printf("+-------+-------+-------+\n");
    for(int row=0; row<SIZE; row++){
        if(row == 3 || row == 6)
    	    printf("+-------+-------+-------+ -\n");
        for(int col=0; col<SIZE; col++){
            if(col == 0 || col == 3 || col == 6)
                printf("| ");
            char c = board_get(s, row, col);
	    if(c == '0' || c == 0)
		c = '.';
            printf("%c ", c);
        }
        printf("| %d\n", row+1);
    }
    printf("+-------+-------+-------+\n");
}

void render_message(const char *msg){
    printf("%s\n", msg);
}

// Features
void render_cell(char value, bool is_initial){
}
void render_prompt(const char *msg){
}
void render_error(const char *msg){
}
