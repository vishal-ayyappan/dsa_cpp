#include <bits/stdc++.h>
using namespace std;

//Recursive Solution

int getMax(vector<vector<int>> &grid, int row, int alice_col, int bob_col){
    //Base Cases
    if (alice_col < 0 || bob_col < 0 || alice_col >= grid[0].size() || bob_col >= grid[0].size()) return -1e8;
    if (row == grid.size()-1){
        if (alice_col == bob_col) return grid[row][alice_col];
        else return grid[row][alice_col] + grid[row][bob_col];
    }
    //Recursive calls
    vector<int> delta = {-1,0,1};
    int maxi = 0;
    for (int i=0; i<delta.size(); i++){
        for (int j=0; j<delta.size(); j++){
            int value = getMax(grid, row+1, alice_col + delta[i], bob_col + delta[j]);
            if (alice_col == bob_col) value += grid[row][alice_col];   
            else value += grid[row][alice_col] + grid[row][bob_col];
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    //Alice (0,0) abd Bob (0, c-1);
    return getMax(grid, 0, 0, c-1);
}

//DP --> Memoization
int getMaxDP(vector<vector<int>> &grid, int row, int alice_col, int bob_col, vector<vector<vector<int>>>& dp){
    if (alice_col < 0 || bob_col < 0 || alice_col >= grid[0].size() || bob_col >= grid[0].size()) return -1e8;
    if (row == grid.size()-1){
        if (alice_col == bob_col) return grid[row][alice_col];
        else return grid[row][alice_col] + grid[row][bob_col];
    }
    if (dp[row][alice_col][bob_col] != -1) return dp[row][alice_col][bob_col];
    //Recursive calls
    vector<int> delta = {-1,0,1};
    int maxi = 0;
    for (int i=0; i<delta.size(); i++){
        for (int j=0; j<delta.size(); j++){
            int value = getMaxDP(grid, row+1, alice_col + delta[i], bob_col + delta[j], dp);
            if (alice_col == bob_col) value += grid[row][alice_col];   
            else value += grid[row][alice_col] + grid[row][bob_col];
            maxi = max(maxi, value);
        }
    }
    dp[row][alice_col][bob_col] = maxi;
    return dp[row][alice_col][bob_col];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    //Alice (0,0) abd Bob (0, c-1);
    //Declare a DP 3D matrix
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
    return getMaxDP(grid, 0, 0, c-1, dp);
}

//Tabulation
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    //Alice (0,0) abd Bob (0, c-1);
    //Declare a DP 3D matrix
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
    //Base Cases (When we are in the last row)
    for (int i=0; i<c; i++){
        for (int j=0; j<c; j++){
            if (i == j) dp[r-1][i][j] = grid[r-1][i];
            else dp[r-1][i][j] = grid[r-1][i] + grid[r-1][j];
        }
    }
    //Bottom up recurrence
    for (int i=r-2; i>=0; i--){
        for (int j1=0; j1<c; j1++){
            for (int j2=0; j2<c; j2++){
                int maxi = -1e8;
                for (int dj1=-1; dj1<=1; dj1++){
                    for (int dj2=-1; dj2<=1; dj2++){
                        if (j1 + dj1 >= 0 && j2 + dj2 >= 0 && j1 + dj1 < c && j2 + dj2 < c){
                            int value = dp[i+1][j1+dj1][j2+dj2];
                            if (j1 == j2) value += grid[i][j1];
                            else value += grid[i][j1] + grid[i][j2];
                            maxi = max(maxi, value);
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c-1];
}

//TC - O(N*M*M*3*3)
//SC - O(N*M*M)



