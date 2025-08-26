#include <bits/stdc++.h>
using namespace std;

//Minimum Path Sum
int getMinSum(vector<vector<int>> &grid, int row, int col, vector<vector<int>>& dp){
    //Base Case
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return INT_MAX;
    if (row == 0 && col == 0) return dp[row][col] = grid[row][col];
    if (dp[row][col] != -1) return dp[row][col];
    //Write the recurrence relation
    int goLeft = getMinSum(grid, row, col-1, dp);
    int goUp = getMinSum(grid, row-1, col, dp);
    int minMovement = min(goLeft, goUp);
    if (minMovement != INT_MAX) return dp[row][col] = grid[row][col] + minMovement;
    return dp[row][col];
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    // dp[i][j] --> min cost sum to go from (i,j) to (0,0)
    getMinSum(grid, n-1, m-1, dp);
    return dp[n-1][m-1];
}

//DP --> Tabulation
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    // dp[i][j] --> min cost sum to go from (i,j) to (0,0)
    //Write the base Case
    dp[0][0] = grid[0][0];
    int sum = grid[0][0];
    for (int row=1; row<n; row++){
        sum += grid[row][0];
        dp[row][0] = sum;
    }
    sum = grid[0][0];
    for (int col=1; col<m; col++){
        sum += grid[0][col];
        dp[0][col] = sum;
    }
    for (int row=1; row<n; row++){
        for (int col=1; col<m; col++){
            int goLeft = dp[row][col-1];
            int goUp = dp[row-1][col];
            dp[row][col] = min(goLeft, goUp) + grid[row][col];
        }
    }
    return dp[n-1][m-1];
}