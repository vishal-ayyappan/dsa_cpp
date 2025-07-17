#include <bits/stdc++.h>
using namespace std;

//Unbounded Knapsack
int getMaxValue(vector<int> &profit, vector<int> &weight, int idx, int w, vector<vector<int>>& dp){
    if (idx == 0){
        if (w==0) dp[idx][w] = INT_MIN;
        else {
            int count = w/weight[idx];
            if (count == 0) dp[idx][w] = INT_MIN;
            else dp[idx][w] = count*profit[idx];
        }
        return dp[idx][w];
    }
    if (dp[idx][w] != -1) return dp[idx][w];
    int notPick = getMaxValue(profit, weight, idx-1, w, dp);
    int pick = INT_MIN;
    if (w >= weight[idx]) pick = profit[idx] + getMaxValue(profit, weight, idx, w-weight[idx], dp);
    dp[idx][w] = max(pick, notPick);
    return dp[idx][w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    //Declare a DP array
    //dp[i][j] --> stores the maximum profit you can get, given that you can take at most "w" weight
    // in the subsequence starting from (0 to idx);
    vector<vector<int>> dp (n, vector<int> (w+1, -1));
    getMaxValue(profit, weight, n-1, w, dp);
    if (dp[n-1][w] == INT_MIN) return 0;
    return dp[n-1][w];
    //dp[n-1][w] maxProfit you can get given that you can take at most w weight in the subsequence (0 to idx)
}