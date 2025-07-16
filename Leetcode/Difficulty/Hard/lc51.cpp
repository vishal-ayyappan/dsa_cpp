#include <bits/stdc++.h>
using namespace std;

//N Queens
bool canBePlaced(vector<string>& board, int row, int col){
    //Check row
    for (int i=0; i<col; i++){
        if (board[row][i] == 'Q') return false;
    }
    //Check Left and right Diagonal
    int i = row;
    int j = col;
    //Left
    while (i >=0 && j >= 0){
        if (board[i][j] == 'Q') return false;
        i--;
        j--;
    }
    int x = row;
    int y = col;
    while (x < board.size() && y >= 0){
        if (board[x][y] == 'Q') return false;
        x++;
        y--;
    }
    return true;
}

void solve(vector<string>& board, int col, vector<vector<string>>& ans){
    if (col == board.size()) {
        ans.push_back(board);
        return;
    }
    //In one column, only one queen can be placed
    for (int i=0; i<board.size(); i++){
        if (canBePlaced(board, i, col)){
            board[i][col] = 'Q';
            solve(board, col+1, ans);
            board[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    //Declare a n*n chessboard
    vector<vector<string>> ans;
    vector<string> board;
    for (int i=0; i<n; i++){
        string res;
        for (int j=0; j<n; j++){
            res.push_back('.');
        }
        board.push_back(res);
    }
    solve(board, 0, ans);
    return ans;
}