#include <bits/stdc++.h>
using namespace std;

//Unique Paths

//1/ Express everything in terms of index
//2/ f(i,j) -> count how many ways, you can reach from (0,0) to (i,j)

//Recursive Code

int getUniquePaths(int row, int col){
    //Base Case
    if (row < 0 || col < 0) return 0;
    if (row == 0 && col == 0) return 1;
    //Move one up
    int up = getUniquePaths(row-1, col);
    int left = getUniquePaths(row, col-1);
    return up + left ;
}

int uniquePaths(int m, int n) {
    int ans = getUniquePaths(m-1, n-1);
    return ans;
}

//Memoization
int getUniquePathsDP(int row, int col, vector<vector<int>>& dp){
    //Base Cases
    if (row<0 || col<0) return 0;
    if (dp[row][col] != -1) return dp[row][col];
    if (row == 0 && col == 0) {
        dp[row][col] = 1;
        return dp[row][col];
    }
    //Recurrence relation
    int moveUp = getUniquePathsDP(row-1, col, dp);
    int moveLeft = getUniquePathsDP(row, col-1, dp);
    dp[row][col] = moveUp + moveLeft;
    return dp[row][col];
}

int uniquePaths(int m, int n) {
    //Create a dp matrix//
    //The DP array dp[i][j] will store the number of unique paths from (0,0) to (i,j).
    vector<vector<int>> dp (m, vector<int> (n, -1));
    getUniquePathsDP(m-1, n-1, dp);
    return dp[m-1][n-1];
}

//TC - O(M*N)
//SC - O(M*N) + O(M-1+N-1)


//Tabulation
int uniquePaths(int m, int n) {
    //Create a dp matrix//
    //The DP array dp[i][j] will store the number of unique paths from (0,0) to (i,j).
    vector<vector<int>> dp (m, vector<int> (n, -1));
    //Write the base case
    dp[0][0] = 1;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (i > 0 && j > 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else if (i > 0) dp[i][j] = dp[i-1][j];
            else if (j > 0) dp[i][j] = dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

//TC - O(M*N)
//SC - O(M*N)

//Space Optimization
int uniquePaths(int m, int n) {
    //Create a dp matrix//
    //The DP array dp[i][j] will store the number of unique paths from (0,0) to (i,j).
    //Write the base case
    vector<int> dp (n, 0);
    for (int i=0; i<m; i++){
        vector<int> temp (n);
        for (int j=0; j<n; j++){
            if (i > 0 && j > 0) temp[j] = dp[j] + temp[j-1];
            else if (i > 0) temp[j] = dp[j];
            else if (j > 0) temp[j] = temp[j-1];
            else temp[j] = 1;
        }
        dp = temp;
    }
    return dp[n-1];
}


//TC - O(M*N)
//SC - O(N)

