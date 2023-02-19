#include <iostream>
#include <unistd.h>
#include "knights.h"

void print(int board[][5]){
    //std::cout << "[0;0H\n";

    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            std::cout << board[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

bool find(int board[][5], int num){
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            if(board[x][y] == num)
                return true;
        }
    }
    return false;
}

bool complete(int board[][5]){
    for(int x = 1; x <= 25; x++){
        if(!(find(board, x)))
            return false;
    }
    return true;
}

void clear(int board[][5], int z){
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            if(board[x][y] >= z)
                board[x][y] = 0;
        }
    }
}

bool done = false;
void solve(int board[][5], int x, int y, int counter){
    if((board[x][y] <= counter && board[x][y] != 0)|| x >= 5 || y >= 5 || x < 0 || y < 0)
        return;
    
    board[x][y] = counter;
    //usleep(100000);
    //print(board);

    if(complete(board)){
        std::cout << std::endl;
        std::cout << "Solution" << std::endl;
        print(board);
        done = true;
        return;
    }

    if(!done){
        solve(board, x - 1, y - 2, counter + 1);
        if(!done) clear(board, counter + 1);
    }
    if(!done){
        solve(board, x - 2, y - 1, counter + 1);
        if(!done) clear(board, counter + 1);
    }
    if(!done){
        solve(board, x + 1, y - 2, counter + 1);
        if(!done) clear(board, counter + 1);
    }     
    if(!done){
        solve(board, x + 2, y - 1, counter + 1);  
        if(!done) clear(board, counter + 1);
    }  
    if(!done){
        solve(board, x - 1, y + 2, counter + 1);
        if(!done) clear(board, counter + 1);
    }     
    if(!done){
        solve(board, x - 2, y + 1, counter + 1);   
        if(!done) clear(board, counter + 1);
    } 
    if(!done){
        solve(board, x + 1, y + 2, counter + 1);   
        if(!done) clear(board, counter + 1);
    }  
    if(!done){
        solve(board, x + 2, y + 1, counter + 1);  
        if(!done) clear(board, counter + 1);
    } 
}