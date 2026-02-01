#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "render.h"

int main(){
    Sudoku *ptr = malloc(sizeof(Sudoku));
    if(ptr == NULL){
        printf("Wrong memory initialzation\n");
        return 1;
    }
    game_init(ptr);
    game_loop(ptr);
    free(ptr);
    return 0;
}
