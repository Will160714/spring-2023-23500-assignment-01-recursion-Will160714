#include <iostream>
#include "knights.h"

int main(){
    int board[5][5] = {{0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}};

    print(board);    
    solve(board, 2, 2, 1); //Starting point is the center
    return 0;
}


