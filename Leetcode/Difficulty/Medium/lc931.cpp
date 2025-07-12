#include <bits/stdc++.h>
using namespace std;

//Minimum path Falling sum

//Recursive Solution 
//f(row, col) gives the mimimum sum from row to the last row.
int getPathSum(vector<vector<int>>& matrix, int row, int col){
    if (col < 0 || col >= matrix.size()) return INT_MAX;
    if (row == matrix.size()-1) return matrix[row][col];
    //Can move in three ways
    int path1 = getPathSum(matrix, row+1, col-1);
    int path2 = getPathSum(matrix, row+1, col);
    int path3 = getPathSum(matrix, row+1, col+1);
    int res = min({path1, path2, path3}) + matrix[row][col];
    return res;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    //There is no fixed starting or ending point
    int n = matrix.size();
    int mini = INT_MAX;
    for (int i=0; i<n; i++){
        int value = getPathSum(matrix, 0, i);
        mini = min(mini, value);
    }
    return mini;
}

//DP --> memoization
int getPathSumDP(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp){
    //Base Cases
    if (col < 0 || col >= matrix.size()) return INT_MAX;
    if (dp[row][col] != -1) return dp[row][col];
    if (row == matrix.size()-1){
        dp[row][col] = matrix[row][col];
        return dp[row][col];
    }
    //3 ways
    int path1 = getPathSumDP(matrix, row+1, col-1, dp);
    int path2 = getPathSumDP(matrix, row+1, col, dp);
    int path3 = getPathSumDP(matrix, row+1, col+1, dp);
    dp[row][col] = min({path1, path2, path3}) + matrix[row][col];
    return dp[row][col];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    //There is no fixed starting or ending point
    int n = matrix.size();
    //Create a DP array
    //dp[i][j] will store the minimum path sum from row i to the last row
    vector<vector<int>> dp (n, vector<int> (n, -1));
    int mini = INT_MAX;
    for (int i=0; i<n; i++){
        if (dp[0][i] == -1) getPathSumDP(matrix, 0, i, dp);
        mini = min(mini, dp[0][i]);
    }
    return mini;
}

//TC - O(N*N*N)
//SC - O(N*N) + O(N)


//DP --> Tabulation
int minFallingPathSum(vector<vector<int>>& matrix) {
    //There is no fixed starting or ending point
    int n = matrix.size();
    //Create a DP array
    //dp[i][j] will store the minimum path sum from row i to the last row
    vector<vector<int>> dp (n, vector<int> (n, -1));
    //Base Cases
    for (int i=0; i<n; i++){
        dp[n-1][i] = matrix[n-1][i];
    }
    for (int i=n-2; i>=0; i--){
        for (int j=n-1; j>=0; j--){
            int path1 = (j < n-1) ? dp[i+1][j+1] : INT_MAX;
            int path2 = dp[i+1][j];
            int path3 = (j > 0) ? dp[i+1][j-1] : INT_MAX;
            dp[i][j] = min({path1, path2, path3}) + matrix[i][j];
        }
    }
    return *min_element(dp[0].begin(), dp[0].end());
}

//TC - O(N*N)
//SC - O(N*N)

//Tabulation with Space Optimization (we only need the next rows sum)
int minFallingPathSum(vector<vector<int>>& matrix) {
    //There is no fixed starting or ending point
    int n = matrix.size();
    vector<vector<int>> dp (n, vector<int> (n, -1));
    vector<int> nextRow (n);
    //Base Cases
    for (int i=0; i<n; i++){
        nextRow[i] = matrix[n-1][i];
    }
    for (int i=n-2; i>=0; i--){
        vector<int> currRow (n);
        for (int j=n-1; j>=0; j--){
            int path1 = (j < n-1) ? nextRow[j+1] : INT_MAX;
            int path2 = nextRow[j];
            int path3 = (j > 0) ? nextRow[j-1] : INT_MAX;
            currRow[j] = min({path1, path2, path3}) + matrix[i][j];
        }
        nextRow = currRow;
    }
    return *min_element(nextRow.begin(), nextRow.end());
}

//TC - O(N*N)
//SC - O(N)

