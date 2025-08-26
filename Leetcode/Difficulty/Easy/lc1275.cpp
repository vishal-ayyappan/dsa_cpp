#include <bits/stdc++.h>
using namespace std;

//Find Winner on a Tic Tac Toe Game

bool isWinningMove(vector<vector<char>>& board, char ch, int row, int col){
    //Check the row
    if (board[row][0] == ch && board[row][1] == ch && board[row][2] == ch) return true;
    //Check the column
    if (board[0][col] == ch && board[1][col] == ch && board[2][col] == ch) return true;
    //Check the diagonal
    if (row == col && board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) return true;
    //Check the other diagonal
    if (row + col == 2 && board[0][2] == ch && board[1][1] == ch && board[2][0] == ch) return true;
    return false;
}

string tictactoe(vector<vector<int>>& moves) {
    int n = moves.size();
    vector<vector<char>> board (3, vector<char> (3));
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            board[i][j] = '-';
        }
    }
    for (int i=0; i<n; i++){
        // A plays
        int r = moves[i][0];
        int c = moves[i][1];
        if (i%2 == 0){
            board[r][c] = 'X';
            if (isWinningMove(board, 'X', r, c)) return "A";
        }
        else{
            board[r][c] = 'O';
            if (isWinningMove(board, 'O', r, c)) return "B";
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] == '-') return "Pending";
        }
    }
    return "Draw";
}