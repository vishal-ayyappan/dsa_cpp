#include <bits/stdc++.h>
using namespace std;

//Rod Cutting Problem

int getMaxProfit(vector<int>& price, int i, int capacity, vector<vector<int>>& dp){
    //Base Case
    if (i == 0) return 0;
    if (dp[i][capacity] != -1) return dp[i][capacity];
    //Do all the stuff (Recurrence relation)
    int pick = 0;
    if (capacity >= i) pick = price[i-1] + getMaxProfit(price, i, capacity-i, dp);
    int notPick = getMaxProfit(price, i-1, capacity, dp);
    dp[i][capacity] = max(pick, notPick);
    return dp[i][capacity];
}

int cutRod(vector<int> &price) {
    //This is similar to the unbounded Knapsack problem
    int n = price.size();
    vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
    getMaxProfit(price, n, n, dp);
    return dp[n][n];
}

//DP --> Tabulation
int cutRod(vector<int> &price) {
    //This is similar to the unbounded Knapsack problem
    int n = price.size();
    vector<vector<int>> dp (n+1, vector<int> (n+1, 0));
    //dp[i][j] --> max profit you can get from 1 to i (1 indexed) given the rod has j length
    for (int i=1; i<=n; i++){
        for (int j=0; j<=n; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if (j >= i) pick = dp[i][j-i] + price[i-1];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n][n];
}

