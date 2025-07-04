#include <bits/stdc++.h>
using namespace std;

//Sudoku Solver

/*
Fill all the empty column, one by one (Backtracking)
*/

bool isSafe(vector<vector<char>>& board, int row, int column, char character){
    int n = board.size();
    //Check the row
    //Check the column
    for (int i=0; i<n; i++){
        if (board[row][i] == character) return false;
        if (board[i][column] == character) return false;
    }
    //Check the box
    int rowIdx = (row/3)*3;
    int colIdx = (column/3)*3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i+rowIdx][j+colIdx] == character) return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    int n = board.size();
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (board[i][j] == '.'){
                for (char k='1'; k<='9'; k++){
                    if (isSafe(board, i, j, k)){
                        board[i][j] = k;
                        if (solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

//TC - Exponential (too big)