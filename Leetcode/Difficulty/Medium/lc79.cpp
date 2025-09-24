#include <bits/stdc++.h>
using namespace std;

//Word Search
bool doesExist(vector<vector<char>>& board, int row, int col, string& ds, string& word, vector<int>& delRow, vector<int>& delCol, 
    vector<vector<bool>>& visited){
    //Base Case
    if (ds.size() == word.size()){
        if (ds == word) return true;
        return false;
    }
    //Check all 4 directions
    for (int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && !visited[nrow][ncol]){
            visited[nrow][ncol] = true;
            ds.push_back(board[nrow][ncol]);
            if (doesExist(board, nrow, ncol, ds, word, delRow, delCol, visited)) return true;
            ds.pop_back();
            visited[nrow][ncol] = false;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    //Can start anywhere
    int n = board.size();
    int m = board[0].size();
    string ds;
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            ds.push_back(board[i][j]);
            visited[i][j] = true;
            if (doesExist(board, i, j, ds, word, delRow, delCol, visited)) return true;
            visited[i][j] = false;
            ds.pop_back();
        }
    }
    return false;
}

//Follow up, Search Pruning
bool doesExist1(vector<vector<char>>& board, int row, int col, string& word, vector<int>& delRow, vector<int>& delCol, 
    vector<vector<bool>>& visited, int idx){
        if (idx == word.size()) return true;
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && !visited[nrow][ncol]){
                if (board[nrow][ncol] == word[idx]){
                    visited[nrow][ncol] = true;
                    if (doesExist1(board, nrow, ncol, word, delRow, delCol, visited, idx+1)) return true;
                    visited[nrow][ncol] = false;
                }
            }
        }
        return false;
    }

bool exist(vector<vector<char>>& board, string word) {
    //Can start anywhere
    int n = board.size();
    int m = board[0].size();
    string ds;
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == word[0]){
                visited[i][j] = true;
                if (doesExist1(board, i, j, word, delRow, delCol, visited, 1)) return true;
                visited[i][j] = false;
            }
        }
    }
    return false;
}
