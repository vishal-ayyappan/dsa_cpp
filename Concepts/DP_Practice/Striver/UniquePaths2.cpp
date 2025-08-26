#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//Unique Paths 2
int getPaths(vector<vector<int>> &mat, vector<vector<int>>& dp, int row, int col){
    //If it is out of bounds
    if (row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size()) return 0;
    //If it is already done
    if (dp[row][col] != -1) return dp[row][col];
    //If it is blocked
    if (mat[row][col] == -1) return dp[row][col] = 0;
    //If it is the starting node
    if (row == 0 && col == 0) return dp[row][col] = 1;
    //Get all the paths
    int goLeft = getPaths(mat, dp, row, col-1);
    int goUp = getPaths(mat, dp, row-1, col);
    dp[row][col] = (goUp + goLeft) % MOD;
    return dp[row][col];
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp (n, vector<int> (m, -1));
    // dp[i][j] --> no of ways to go from (i,j) to (0,0);
    getPaths(mat, dp, n-1, m-1);
    return dp[n-1][m-1];
}


//DP --> Tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp (n, vector<int> (m, -1));
    // dp[i][j] --> no of ways to go from (i,j) to (0,0);
    //Write the base Case
    if (mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;
    dp[0][0] = 1;
    int row = 1;
    while (row < n){
        if (mat[row][0] == -1) break;
        dp[row][0] = 1;
        row++;
    }
    while (row < n) {
        dp[row][0] = 0;
        row++;
    }
    int col = 1;
    while (col < m){
        if (mat[0][col] == -1) break;
        dp[0][col] = 1;
        col++;
    }
    //If it breaks early, meaning there is a blockage
    while (col < m) {
        dp[0][col] = 0;
        col++;
    }
    for (int row=1; row<n; row++){
        for (int col=1; col<m; col++){
            if (mat[row][col] == -1) dp[row][col] = 0;
            else{
                int goUp = dp[row-1][col];
                int goLeft = dp[row][col-1];
                dp[row][col] = (goUp + goLeft)%MOD;
            }
        }
    }
    return dp[n-1][m-1];
}

