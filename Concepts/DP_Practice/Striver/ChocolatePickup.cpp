#include <bits/stdc++.h>
using namespace std;

//Cherry Pickup
int getMaxSum(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int col1, int col2){
    //Base Cases
    //If it goes out of bounds
    if (col1 < 0 || col2 < 0 || col1 > grid[0].size()-1 || col2 > grid[0].size()-1) return 0;
    if (dp[row][col1][col2] != -1) return dp[row][col1][col2];
    //If it is at the last row
    if (row == grid.size()-1){
        if (col1 == col2) return dp[row][col1][col2] = grid[row][col1];
        else return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
    }
    //Write the recurrence relation
    //There can be 9 possibilities
    int maxi = 0;
    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            int value = getMaxSum(grid, dp, row+1, col1+i, col2+j);
            maxi = max(maxi, value);
        }
    }
    dp[row][col1][col2] = maxi;
    //If they are the same, you just pick once
    if (col1 == col2) dp[row][col1][col2] += grid[row][col1];
    else dp[row][col1][col2] += grid[row][col1] + grid[row][col2];
    return dp[row][col1][col2];
}

int solve(int n, int m, vector<vector<int>>& grid) {
    //It depends on the row and the col of the first person asn the col of the second person
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
    getMaxSum(grid, dp, 0, 0, m-1);
    return dp[0][0][m-1];
}

//DP --> Tabulation
int solve(int n, int m, vector<vector<int>>& grid) {
    //It depends on the row and the col of the first person asn the col of the second person
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
    // dp[i][j][k] --> max chocolates you pick from i to n-1 given 1 picks j and other picks k at ith day
    //Write the base Case
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            if (i == j) dp[n-1][i][j] = grid[n-1][i];
            else dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
        }
    }
    //Do what you did in recursion
    for (int row=n-2; row>=0; row--){
        for (int col1=0; col1<m; col1++){
            for (int col2=0; col2<m; col2++){
                //Check all 9 possibilities
                int maxi = 0;
                for (int left=-1; left<=1; left++){
                    for (int right=-1; right<=1; right++){
                        int ncol1 = col1 + left;
                        int ncol2 = col2 + right;
                        if (ncol1 < 0 || ncol2 < 0 || ncol1 >= m || ncol2 >= m) continue;
                        int value = dp[row+1][ncol1][ncol2];
                        maxi = max(maxi, value);
                    }
                }
                if (col1 == col2) maxi += grid[row][col1];
                else maxi += grid[row][col1] + grid[row][col2];
                dp[row][col1][col2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}
