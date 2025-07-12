#include <bits/stdc++.h>
using namespace std;

//Minimum Path sum on a triangular grid
//f(i,j) will tell the minimum path sum from 0th row to n-1th row

int getMinimum(vector<vector<int>>& triangle, int row, int col){
    if (col < 0 && col >= triangle[row].size()) return INT_MAX;
    if (row == triangle.size()-1) return triangle[row][col];
    //Move one step down to the same col and to col + 1
    int path1 = getMinimum(triangle, row+1, col);
    int path2 = getMinimum(triangle, row+1, col+1);
    return min(path1, path2) + triangle[row][col];

}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return getMinimum(triangle, 0, 0);
}

//TC - O(2*N*N)
//SC - O(N*N) + O(N)

//DP --> with memoization
int getMinimumDP(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp){
    if (col >= triangle[row].size()) return INT_MAX;
    if (dp[row][col] != -1) return dp[row][col];
    if (row == triangle.size()-1){
        dp[row][col] = triangle[row][col];
        return dp[row][col];
    }
    //Go south
    int path1 = getMinimumDP(triangle, row+1, col, dp);
    //Go south-east
    int path2 = getMinimumDP(triangle, row+1, col+1, dp);
    dp[row][col] = min(path1, path2) + triangle[row][col];
    return dp[row][col];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp;
    for (int i=0; i<n; i++){
        vector<int> row (i+1, 0);
        for (int j=0; j<=i; j++){
            row[j] = -1;
        }
        dp.push_back(row);
    }
    getMinimumDP(triangle, 0, 0, dp);
    return dp[0][0];
}


//DP --> Tabulation
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    //Create the DP array
    vector<vector<int>> dp;
    for (int i=0; i<n; i++){
        vector<int> row (i+1, 0);
        for (int j=0; j<=i; j++){
            row[j] = -1;
        }
        dp.push_back(row);
    }
    //Base Cases
    for (int i=0; i<n; i++){
        dp[n-1][i] = triangle[n-1][i];
    }
    //Do the same thing you did in recursion
    for (int i=n-2; i>=0; i--){
        for (int j=i; j>=0; j--){
            int path1 = dp[i+1][j];
            int path2 = dp[i+1][j+1];
            dp[i][j] = min(path1, path2) + triangle[i][j];
        }
    }
    return dp[0][0];
}

//TC - O(M*N)
//SC - O(M*N)

//Space Optimization
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    //Create the next
    vector<int> next (n, 0);
    for (int i=0; i<n; i++){
        next[i] = triangle[n-1][i];
    }
    //Do the same thing you did in recursion
    for (int i=n-2; i>=0; i--){
        vector<int> curr (i+1);
        for (int j=i; j>=0; j--){
            int path1 = next[j];
            int path2 = next[j+1];
            curr[j] = min(path1, path2) + triangle[i][j]; 
        }
        next = curr;
    }
    return next[0];
}

