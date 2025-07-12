#include <bits/stdc++.h>
using namespace std;

//Minimum Path Sum

//Recursion
int getSum(vector<vector<int>>& grid, int row, int col){
    //Base Cases
    if (row < 0 || col < 0) return INT_MAX; //Sum does not exist
    if (row == 0 && col == 0) return grid[row][col];
    int leftSum = getSum(grid, row, col-1);
    int topSum = getSum(grid, row-1, col);
    return min(leftSum, topSum) + grid[row][col];
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    // f(row, col) represents the minimum path sum from (row,col) to (0,0).
    int ans = getSum(grid, m-1, n-1);
    return ans;
}

//TC - O(2^M*N)
//SC - O(M*N) + O(M-1+N-1)

//DP --> Memoization
int getSumDP(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp){
    //Base Cases
    if (row < 0 || col < 0) return INT_MAX;
    if (dp[row][col] != -1) return dp[row][col];
    if (row == 0 && col == 0){
        dp[row][col] = grid[row][col];
        return dp[row][col];
    }
    //Logic
    int leftSum = getSumDP(grid, row, col-1, dp);
    int upSum = getSumDP(grid, row-1, col, dp);
    dp[row][col] = min(leftSum, upSum) + grid[row][col];
    return dp[row][col];
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    //Declare a dp matrix;
    vector<vector<int>> dp (m, vector<int> (n, -1));
    // dp[row][col] represents the minimum path sum from (row,col) to (0,0).
    getSumDP(grid, m-1, n-1, dp);
    return dp[m-1][n-1];
}

//TC - O(M*N)
//SC - O(M*N) + O(M-1+N-1)

//DP --> Tabulation
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    //Declare a dp matrix;
    vector<vector<int>> dp (m, vector<int> (n, -1));
    // dp[row][col] represents the minimum path sum from (row,col) to (0,0).
    //Write down the base cases
    dp[0][0] = grid[0][0];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (i == 0 && j == 0) dp[i][j] = grid[0][0];
            else{
                int leftSum = INT_MAX;
                int upSum = INT_MAX;
                if (i > 0) upSum = dp[i-1][j];
                if (j > 0) leftSum = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(leftSum, upSum);
            }
        }
    }
    return dp[m-1][n-1];
}

//TC - O(M*N)
//SC - O(M*N)

//Space Optimization (You only need the prevRow and the prevCol)
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prevRow (n);
    for (int i=0; i<m; i++){
        vector<int> currRow (n);
        for (int j=0; j<n; j++){
            if (i == 0 && j == 0) currRow[j] = grid[0][0];
            else{
                int leftSum = INT_MAX;
                int upSum = INT_MAX;
                if (i > 0) upSum = prevRow[j];
                if (j > 0) leftSum = currRow[j-1];
                currRow[j] = grid[i][j] + min(leftSum, upSum);
            }
        }
        prevRow = currRow;
    }
    return prevRow[n-1];
}

//TC - O(M*N)
//SC - O(N)
