#include <iostream>
#include "knights.h"

int main(){
    int board[5][5] = {{0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}};
    print(board);
    solve(board, 0, 1, 0);
    return 0;
}


