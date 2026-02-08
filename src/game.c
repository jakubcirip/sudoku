#include "game.h"

void game_init(Sudoku *s){
    board_clear(s);
    board_set(s, 0, 0, '8');
    board_set(s, 0, 1, '6');
    board_set(s, 0, 2, '1');
    board_set(s, 0, 3, '7');
    board_set(s, 0, 4, '9');
    board_set(s, 0, 5, '4');
    board_set(s, 0, 6, '3');
    board_set(s, 0, 7, '5');
    board_set(s, 0, 8, '2');

    board_set(s, 1, 0, '3');
    board_set(s, 1, 1, '5');
    board_set(s, 1, 2, '2');
    board_set(s, 1, 3, '1');
    board_set(s, 1, 4, '6');
    board_set(s, 1, 5, '8');
    board_set(s, 1, 6, '7');
    board_set(s, 1, 7, '4');
    board_set(s, 1, 8, '9');

    board_set(s, 2, 0, '4');
    board_set(s, 2, 1, '9');
    board_set(s, 2, 2, '7');
    board_set(s, 2, 3, '2');
    board_set(s, 2, 4, '5');
    board_set(s, 2, 5, '3');
    board_set(s, 2, 6, '1');
    board_set(s, 2, 7, '8');
    board_set(s, 2, 8, '6');

    board_set(s, 3, 0, '2');
    board_set(s, 3, 1, '1');
    board_set(s, 3, 2, '8');
    board_set(s, 3, 3, '9');
    board_set(s, 3, 4, '7');
    board_set(s, 3, 5, '5');
    board_set(s, 3, 6, '6');
    board_set(s, 3, 7, '3');
    board_set(s, 3, 8, '4');

    board_set(s, 4, 0, '6');
    board_set(s, 4, 1, '7');
    board_set(s, 4, 2, '5');
    board_set(s, 4, 3, '3');
    board_set(s, 4, 4, '4');
    board_set(s, 4, 5, '1');
    board_set(s, 4, 6, '9');
    board_set(s, 4, 7, '2');
    board_set(s, 4, 8, '8');

    board_set(s, 5, 0, '9');
    board_set(s, 5, 1, '3');
    board_set(s, 5, 2, '4');
    board_set(s, 5, 3, '6');
    board_set(s, 5, 4, '8');
    board_set(s, 5, 5, '2');
    board_set(s, 5, 6, '5');
    board_set(s, 5, 7, '1');
    board_set(s, 5, 8, '7');

    board_set(s, 6, 0, '5');
    board_set(s, 6, 1, '2');
    board_set(s, 6, 2, '6');
    board_set(s, 6, 3, '8');
    board_set(s, 6, 4, '1');
    board_set(s, 6, 5, '9');
    board_set(s, 6, 6, '4');
    board_set(s, 6, 7, '7');
    board_set(s, 6, 8, '3');

    board_set(s, 7, 0, '7');
    board_set(s, 7, 1, '4');
    board_set(s, 7, 2, '3');
    board_set(s, 7, 3, '5');
    board_set(s, 7, 4, '2');
    board_set(s, 7, 5, '6');
    board_set(s, 7, 6, '8');
    board_set(s, 7, 7, '9');
    board_set(s, 7, 8, '1');

    board_set(s, 8, 0, '1');
    board_set(s, 8, 1, '8');
    board_set(s, 8, 2, '9');
    board_set(s, 8, 3, '4');
    board_set(s, 8, 4, '3');
    board_set(s, 8, 5, '7');
    board_set(s, 8, 6, '2');
    // board_set(s, 8, 7, '6');
    // board_set(s, 8, 8, '5');


    board_copy_initial(s);
    render_message("Hello player!\n");
    // render_board(s);
}

void game_loop(Sudoku *s){
    int row=0, col=0;
    char value;
    render_message("To end game enter 'q'.\n");
    render_board(s);

    while(true){
        if(game_is_finished(s)){
            printf("\n\n");
            render_board(s);
            render_message("Congratulations! You have solved the sudoku.\n");
            break;
        }
        if(!game_input(&row, &col, &value)){   
            render_message("Game ended by player!");
            break;
        } else { 
		if(game_is_initial(s, row, col)){
			render_message("This number cannot be changed!\n");
			render_board(s);
        		continue;
        	}
        	if(validate_move(s, row, col, value)){
            		render_message("Invalid move!\n");
			render_board(s);
            		continue;
        	}
            	game_apply_move(s, row, col, value);
	    	render_board(s);
	}
    }
}

bool game_input(int *row, int *col, char *value){
    char buffer[100];
    int user_row=0, user_col=0;
    char user_value;
    while(true){
        render_message("Make a move,\n Enter: <row_number> <col_number> <value> to insert.");
        render_message("For example: '3' '8' '5'");
        if((fgets(buffer, sizeof(buffer), stdin)) == NULL){
            printf("Ending game...\n");
            return false;
        }
        if(buffer[0] == 'q' || buffer[0] == 'Q'){
                printf("Ending game...\n");
                printf("Game over\n");
                return false;
            }
        int parsed = sscanf(buffer, " %d %d %c", &user_row, &user_col, &user_value);
        if(parsed != 3){
            printf("Wrong input!\n");
            printf("Try again...\n");
            continue;
        }
        if(user_row < 1 || user_row > 9){
            printf("Wrong number of row [1-9].\n");
            printf("Try again...\n");
            continue;
        }
        if(user_col < 1 || user_col > 9){
            printf("Wrong number of column [1-9].\n");
            printf("Try again...\n");
            continue;
        }
        if(user_value < '1' || user_value > '9'){
            printf("Wrong value [1-9].\n");
            printf("Try again...\n");
            continue;
        }
        printf("You entered: Row=%d, Column=%d and Value to insert=%c\n",user_row, user_col, user_value);
        *row=user_row-1;
        *col=user_col-1;
        *value=user_value;
        return true;
    }
}

bool game_is_initial(const Sudoku *s, int row, int col){
    return s->initial[row][col];
}

void game_apply_move(Sudoku *s, int row, int col, char value){
    board_set(s, row, col, value);
}

bool game_is_finished(const Sudoku *s){
    if(board_is_full(s) && validate_board(s))
        return true;
    else
        return false;
}
