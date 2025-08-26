#include <bits/stdc++.h>
using namespace std;

//Unique Paths

int countPaths(vector<vector<int>>& dp, int row, int col){
    //if you go out of bounds, you return 0;
    if (row < 0 || col < 0 || row >= dp.size() || col >= dp[0].size()) return 0;
    if (row == 0 && col == 0) return dp[row][col] = 1;
    if (dp[row][col] != -1) return dp[row][col];
    //Do all the stuff
    int goUp = countPaths(dp, row-1, col);
    int goLeft = countPaths(dp, row, col-1);
    dp[row][col] = goLeft + goUp;
    return dp[row][col];
}

int numberOfPaths(int m, int n) {
    vector<vector<int>> dp (m, vector<int> (n, -1));
    //dp[i][j] --> no of ways to go from (i,j) to (0,0);
    //You can move up or left
    //You do that for each cell
    countPaths(dp, m-1, n-1);
    return dp[m-1][n-1];
}

//DP --> Tabulation

int numberOfPaths(int m, int n){
    vector<vector<int>> dp (m, vector<int> (n, -1));
    //dp[i][j] --> numbers of ways to go from (i,j) to (0,0)
    //Base Case
    dp[0][0] = 1;
    for (int row=1; row<m; row++) dp[row][0] = 1;
    for (int col=1; col<n; col++) dp[0][col] = 1;
    for (int row=1; row<m; row++){
        for (int col=1; col<n; col++){
            //Can move left and up
            int goUp = dp[row-1][col];
            int goLeft = dp[row][col-1];
            dp[row][col] = goUp + goLeft;
        }
    }
    return dp[m-1][n-1];
}