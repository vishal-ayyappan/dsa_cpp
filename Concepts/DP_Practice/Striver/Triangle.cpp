#include <bits/stdc++.h>
using namespace std;

//Triangle
int getMinPath(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row, int col){
    //If you reach the last row
    if (row == triangle.size()-1) return  dp[row][col] = triangle[row][col];
    if (dp[row][col] != -1) return dp[row][col];
    //You can only go j and j+1
    int down = getMinPath(triangle, dp, row+1, col);
    int down_right = getMinPath(triangle, dp, row+1, col+1);
    dp[row][col] = min(down, down_right) + triangle[row][col];
    return dp[row][col];
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	//Here the starting point is fixed
    vector<vector<int>> dp (n);
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            dp[i].push_back(-1);
        }
    }
    //dp[i][j] --> minimum sum path from (i,j) to (n-1,x)
    getMinPath(triangle, dp, 0, 0);
    return dp[0][0];
}

//DP --> Tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n){
	//Here the starting point is fixed
    vector<vector<int>> dp (n);
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            dp[i].push_back(-1);
        }
    }
    //dp[i][j] --> minimum sum path from (i,j) to (n-1,x)
    //Base Case
    for (int i=0; i<n; i++) dp[n-1][i] = triangle[n-1][i];
    //Do what you did in memo
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            int down = dp[i+1][j];
            int down_right = dp[i+1][j+1];
            dp[i][j] = min(down, down_right) + triangle[i][j];
        }
    }
    return dp[0][0];
}
