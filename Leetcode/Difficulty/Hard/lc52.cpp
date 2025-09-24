#include <bits/stdc++.h>
using namespace std;

//N Queens 2
bool canBePlaced(vector<string> board, int row, int col){
    //Check row
    int n = board.size();
    for (int i=0; i<n; i++){
        if (board[row][i] == 'Q') return false;
    }
    //Check column
    for (int i=0; i<n; i++){
        if (board[i][col] == 'Q') return false;
    }
    //Check left up
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0){
        if (board[i][j] == 'Q') return false;
        i--;
        j--;
    }
    //Check left down
    i = row;
    j = col;
    while (i < n && j >= 0){
        if (board[i][j] == 'Q') return false;
        i++;
        j--;
    }
    return true;
}

int getNumber(vector<string> board, int column){
    if (column == board.size()) return 1;
    //Go for each column
    int n = board.size();
    int total = 0;
    //For each column
    for (int i=0; i<n; i++){
        if (canBePlaced(board, i, column)){
            board[i][column] = 'Q';
            int val = getNumber(board, column+1);
            total += val;
            board[i][column] = '.';
        }
    }
    return total;
}

int totalNQueens(int n) {
    vector<string> board;
    //Get the initial board
    for (int i=0; i<n; i++){
        string initial;
        for (int i=0; i<n; i++){
            initial.push_back('.');
        }
        board.push_back(initial);
    }
    //Have to get the number of solutions
    int result = getNumber(board, 0);
    return result;
}