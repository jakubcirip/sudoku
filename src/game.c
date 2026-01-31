#include "game.h"

void game_init(struct sudoku *s){
    board_clear(s);
    board_set(s, 0, 3, '7');
    board_set(s, 0, 4, '9');
    board_set(s, 0, 7, '5');
    board_set(s, 1, 0, '3');
    board_set(s, 1, 1, '5');
    board_set(s, 1, 2, '2');
    board_set(s, 1, 5, '8');
    board_set(s, 1, 7, '4');
    board_set(s, 2, 7, '8');
    board_set(s, 3, 1, '1');
    board_set(s, 3, 4, '7');
    board_set(s, 3, 8, '4');
    board_set(s, 4, 0, '6');
    board_set(s, 4, 3, '3');
    board_set(s, 4, 5, '1');
    board_set(s, 4, 8, '8');
    board_set(s, 5, 0, '9');
    board_set(s, 5, 4, '8');
    board_set(s, 5, 7, '1');
    board_set(s, 6, 1, '2');
    board_set(s, 7, 1, '4');
    board_set(s, 7, 3, '5');
    board_set(s, 7, 6, '8');
    board_set(s, 7, 7, '9');
    board_set(s, 7, 8, '1');
    board_set(s, 8, 1, '8');
    board_set(s, 8, 4, '3');
    board_set(s, 8, 5, '7');

    board_copy_initial(s);
    render_message("Hello player!\n");
    render_board(s);
}

void game_loop(struct sudoku *s){
    int row=0, col=0;
    char value;
    while(true){
        render_board(s);
        render_message("To end game enter 'q' or '0'\n");
        game_input(row, col, value);
        if(game_is_initial(s, row, col)){
            render_message("This number cannot be changed!\n");
            continue;
        }
        if(validate_move(s, row, col, value)){
            render_message("Invalid move\n");
            continue;
        }
        if(!game_input(row, col, value)){   
            render_message("Game ended by player!");
            break;
        } else 
            game_apply_move(s, row, col, value);

        if(game_is_finished(s)){
            render_board(s);
            render_message("Congratulations! You have solved the sudoku\n");
            break;
        }

    }
}

bool game_input(int *row, int *col, char *value){
    char buffer[100];
    int user_row=0, user_col=0;
    char user_value;
    while(true){
        render_message("Make a move,\n Enter: <row_number> <col_number> <value> to insert\n");
        render_message("For example: 3 8 5\n");
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
            printf("Wrong input\n");
            printf("Try again...\n");
            continue;
        }
        if(parsed == 3){
            if(user_row == 0){
                printf("Ending game...\n");
                printf("Game over\n");
                return false;
            }
        }
        if(user_row < 1 || user_row > 9){
            printf("Wrong number of row [1-9]\n");
            printf("Try again...\n");
            continue;
        }
        if(user_col < 1 || user_col > 9){
            printf("Wrong number of column [1-9]\n");
            printf("Try again...\n");
            continue;
        }
        if(user_value < '1' || user_value > '9'){
            printf("Wrong value [1-9]\n");
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

bool game_is_initial(const struct sudoku *s, int row, int col){

}

void game_apply_move(struct sudoku *s, int row, int col, char value){

}

bool game_is_finished(const struct sudoku *s){}