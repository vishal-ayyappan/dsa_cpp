#include <bits/stdc++.h>
using namespace std;

//Word Search II
void getWords(vector<vector<char>>& board, int row, int col, string& ds, unordered_set<string>& ans,
    vector<vector<bool>>& visited, unordered_map<string, int>& mpp, int maxi, vector<int>& delRow, vector<int>& delCol){
        //Base Case
        if (ds.length() > maxi) return;
        //If it is already found out
        if (mpp.find(ds) != mpp.end() && ans.count(ds) == 0) ans.insert(ds);
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && !visited[nrow][ncol]){
                ds.push_back(board[nrow][ncol]);
                visited[nrow][ncol] = true;
                getWords(board, nrow, ncol, ds, ans, visited, mpp, maxi, delRow, delCol);
                visited[nrow][ncol] = false;
                ds.pop_back();
            }
        }
    }

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m = board.size();
    int n = board[0].size();
    //Store all the words in a map
    unordered_map<string, int> mpp;
    int size = words.size();
    int maxi = 0;
    for (int i=0; i<size; i++) {
        int len = words[i].length();
        mpp[words[i]]++;
        maxi = max(maxi, len);
    }
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    unordered_set<string> ans;
    string ds;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            ds.push_back(board[i][j]);
            visited[i][j] = true;
            getWords(board, i, j, ds, ans, visited, mpp, maxi, delRow, delCol);
            visited[i][j] = false;
            ds.pop_back();
        }
    }
    vector<string> res;
    for (auto& s : ans){
        res.push_back(s);
    }
    return res;
}