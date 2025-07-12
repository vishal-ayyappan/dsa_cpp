#include <bits/stdc++.h>
using namespace std;

//If it is an obstacle (return 0)

int getPaths(vector<vector<int>>& obstacleGrid, int row, int col){
    if (row < 0 || col < 0) return 0;
    //Check if there is an obstacle
    if (obstacleGrid[row][col] == 1) return 0;
    if (row == 0 && col == 0) return 1;
    int moveLeft = getPaths(obstacleGrid, row, col-1);
    int moveUp = getPaths(obstacleGrid, row-1, col);
    return moveLeft + moveUp;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int ans = getPaths(obstacleGrid, m-1, n-1);
    return ans;
}

//Memoization
int getPathsDP(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>>& dp){
    //Do the same steps as recursion
    if (row < 0 || col < 0) return 0;
    if (dp[row][col] != -1) return dp[row][col];
    if (obstacleGrid[row][col] == 1) {
        dp[row][col] = 0;
        return dp[row][col];
    }
    if (row == 0 && col == 0){
        dp[row][col] = 1;
        return dp[row][col];
    }
    int moveUp = getPathsDP(obstacleGrid, row-1, col, dp);
    int moveLeft = getPathsDP(obstacleGrid, row, col-1, dp);
    dp[row][col] = moveUp + moveLeft;
    return dp[row][col];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    //Declare a DP array
    //dp[i][j] tells you the total unique paths from (i,j) to (0,0).
    vector<vector<int>> dp (m, vector<int> (n, -1));
    getPathsDP(obstacleGrid, m-1, n-1, dp);
    return dp[m-1][n-1];
}

//Tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    //Declare a DP array
    //dp[i][j] tells you the total unique paths from (i,j) to (0,0).
    vector<vector<int>> dp (m, vector<int> (n, -1));
    //Edge Cases
    dp[0][0] = 1;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else{
                if (i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int moveLeft = 0;
                    int moveUp = 0;
                    if (i>0) moveUp = dp[i-1][j];
                    if (j>0) moveLeft = dp[i][j-1];
                    dp[i][j] = moveLeft + moveUp;
                }
            }
        }
    }
    return dp[m-1][n-1];
}

//Space Optimization
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    //You only need the prevRow.
    vector<int> prev (n, 0);
    //Edge Cases
    prev[0] = 1;
    for (int i=0; i<m; i++){
        vector<int> temp (n);
        for (int j=0; j<n; j++){
            if (obstacleGrid[i][j] == 1) temp[j] = 0;
            else{
                if (i == 0 && j == 0) temp[j] = 1;
                else{
                    int moveLeft = 0;
                    int moveUp = 0;
                    if (i>0) moveUp = prev[j];
                    if (j>0) moveLeft = temp[j-1];
                    temp[j] = moveLeft + moveUp;
                }
            }
        }
        prev = temp;
    }
    return prev[n-1];
}



