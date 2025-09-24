#include <bits/stdc++.h>
using namespace std;

//Longest Increasing path in a matrix (Graph + DP)
int getLongestPath(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp, vector<int>& delRow, vector<int>& delCol){
    if (dp[row][col] != -1) return dp[row][col];
    int m = matrix.size();
    int n = matrix[0].size();
    int length = 1;
    for (int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && matrix[nrow][ncol] > matrix[row][col]){
            int len = 1 + getLongestPath(matrix, nrow, ncol, dp, delRow, delCol);
            length = max(length, len);
        }
    }
    return dp[row][col] = length;
}


int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp (m, vector<int> (n, -1));
    // dp[i][j] --> longest increasing path in the matrix starting from (i,j)
    int maxi = 1;
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    int length = 0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            int len = getLongestPath(matrix, i, j, dp, delRow, delCol);
            maxi = max(maxi, len);
        }
    }
    return maxi;
}