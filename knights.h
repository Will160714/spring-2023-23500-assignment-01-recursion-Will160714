#pragma once

void print(int board[][5]);
void clear(int board[][5], int x);
bool find(int board[][5], int num);
bool complete(int board[][5]);
void solve(int board[][5], int x, int y, int counter);
