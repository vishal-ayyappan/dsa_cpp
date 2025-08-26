#include <bits/stdc++.h>
using namespace std;

//Unbounded Knapsack

int getMaxProfit(vector<int>& val, vector<int>& wt, int i, int capacity, vector<vector<int>>& dp){
    //Base Case
    if (i < 0) return 0;
    if (dp[i][capacity] != -1) return dp[i][capacity];
    //Do all the stuff
    //If you pick
    int pick = 0;
    if (capacity >= wt[i]) pick = val[i] + getMaxProfit(val, wt, i, capacity-wt[i], dp);
    //If you do not pick
    int notPick = getMaxProfit(val, wt, i-1, capacity, dp);
    dp[i][capacity] = max(pick, notPick);
    return dp[i][capacity];
}

int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //You have to get the max Profit
    int n = val.size();
    vector<vector<int>> dp (n, vector<int> (capacity+1, -1));
    // dp[i][j] --> max Profit you can get from the array (0 to i-1) given you can take atleast 'j' capacity
    getMaxProfit(val, wt, n-1, capacity, dp);
    return dp[n-1][capacity];
}

//DP --> Tabulation
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //You have to get the max Profit
    int n = val.size();
    vector<vector<int>> dp (n, vector<int> (capacity+1, 0));
    // dp[i][j] --> max Profit you can get from the array (0 to i-1) given you can take atleast 'j' capacity
    //Write the base cases
    for (int i=0; i<n; i++){
        for (int j=0; j<=capacity; j++){
            int notPick = 0;
            if (i > 0) notPick = dp[i-1][j];
            int pick = 0;
            if (j >= wt[i]) pick = val[i] + dp[i][j-wt[i]];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n-1][capacity];
}
