#include <bits/stdc++.h>
using namespace std;

// 2 players at a time, 3 parameters -> row, col of p1 and col of p2.
int getMax(vector<vector<int>>& grid, int row, int robot1_col, int robot2_col){
    //If out of bounds
    if (robot1_col < 0 || robot2_col < 0 || robot1_col > grid[0].size()-1 || robot2_col > grid[0].size()-1) return -1e8;
    //If at last row
    if (row == grid.size()-1){
        if (robot1_col == robot2_col) return grid[row][robot1_col];
        else return grid[row][robot1_col] + grid[row][robot2_col];
    }
    //Find max of all the possibilities
    int maxi = -1e8;
    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            int value = getMax(grid, row-1, robot1_col+i, robot2_col+j);
            if (robot1_col == robot2_col) value += grid[row][robot1_col];
            else value += grid[row][robot1_col] + grid[row][robot2_col];
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    return getMax(grid, 0, 0, m-1);
}

//DP --> memoization
int getMaxDP(vector<vector<int>>& grid, int row, int robot1_col, int robot2_col, vector<vector<vector<int>>>& dp){
    //Base Cases
    if (robot1_col < 0 || robot2_col < 0 || robot1_col > grid[0].size()-1 || robot2_col > grid[0].size()-1) return -1e8;
    if (dp[row][robot1_col][robot2_col] != -1) return dp[row][robot1_col][robot2_col];
    if (row == grid.size()-1){
        int value;
        if (robot1_col == robot2_col) value = grid[row][robot1_col];
        else value = grid[row][robot1_col] + grid[row][robot2_col];
        dp[row][robot1_col][robot2_col] = value;
        return dp[row][robot1_col][robot2_col];
    }
    int maxi = -1e8;
    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            int call = getMaxDP(grid, row+1, robot1_col+i, robot2_col+j, dp);
            if (robot1_col == robot2_col) call += grid[row][robot1_col];
            else call += grid[row][robot1_col] + grid[row][robot2_col];
            maxi = max(maxi, call);
        }
    }
    dp[row][robot1_col][robot2_col] = maxi;
    return dp[row][robot1_col][robot2_col];
}


int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
    getMaxDP(grid, 0, 0, m-1, dp);
    return dp[0][0][m-1];
}
