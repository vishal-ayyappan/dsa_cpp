#include <bits/stdc++.h>
using namespace std;

/*
How to know it is Valid is the key concept
*/

bool isValid(vector<vector<char>>& board, int row, int column){
    char ch = board[row][column];
    int n = board.size();
    for (int i=0; i<n; i++){
        if (column != i && board[row][i] == ch) return false;
        if (row != i && board[i][column] == ch) return false;
    }
    //Check the box
    int rowIdx = (row/3)*3;
    int columnIdx = (column/3)*3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (((rowIdx + i) == row) && ((columnIdx + j) == column)) continue;
            if (board[rowIdx+i][columnIdx+j] == ch) return false;
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    int n = board.size();
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (board[i][j] == '.') continue;
            if (!isValid(board,i,j)) return false;
        }
    }
    return true;
}