#include <bits/stdc++.h>
using namespace std;

//Coin Change 

// f(idx, amount) --> minimum no of coins to get amount from the combination of 0 to i coins
int getMinCoins(vector<int>& coins, int idx, int amount){
    if (idx == 0) {
        if (amount == 0) return 0;
        if (amount%coins[idx] != 0) return INT_MAX-1;
        int coinsNeeded = amount/coins[idx];
        return coinsNeeded;
    }
    int notPick = getMinCoins(coins, idx-1, amount);
    int pick = INT_MAX-1;
    if (amount >= coins[idx]) pick = 1 + getMinCoins(coins, idx, amount-coins[idx]);
    return min(pick, notPick);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int res = getMinCoins(coins, n-1, amount);
    if (res == INT_MAX-1) return -1;
    return res;
}

//DP --> Memoization
//dp[idx][amount] --> min no of coins where coins can be taken from range 0 to idx, where their sum is amount
int getMinCoinsDP(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp){
    if (idx == 0){
        if (amount == 0) dp[idx][amount] = 0;
        else if (amount % coins[idx] != 0) dp[idx][amount] = INT_MAX-1;
        else dp[idx][amount] =  amount/coins[idx];
        return dp[idx][amount];
    }
    if (dp[idx][amount] != -1) return dp[idx][amount];
    int notPick = getMinCoinsDP(coins, idx-1, amount, dp);
    int pick = INT_MAX-1;
    if (amount >= coins[idx]) pick = 1 + getMinCoinsDP(coins, idx, amount-coins[idx], dp);
    dp[idx][amount] = min(pick, notPick);
    return dp[idx][amount];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    //Declare a DP array
    vector<vector<int>> dp (n, vector<int> (amount+1, -1));
    getMinCoinsDP(coins, n-1, amount, dp);
    if (dp[n-1][amount] == INT_MAX-1) return -1;
    return dp[n-1][amount];
}

//DP --> Tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    //Declare a DP array
    vector<vector<int>> dp (n, vector<int> (amount+1, -1));
    //Base Cases
    dp[0][0] = 0;
    for (int i=1; i<=amount; i++){
        if (i % coins[0] != 0) dp[0][i] = INT_MAX-1;
        else dp[0][i] = i/coins[0];
    }
    for (int i=1; i<n; i++){
        for (int j=0; j<=amount; j++){
            int notPick = dp[i-1][j];
            int pick = INT_MAX-1;
            if (j >= coins[i]) pick = 1 + dp[i][j-coins[i]];
            dp[i][j] = min(pick, notPick);
        }
    }
    if (dp[n-1][amount] == INT_MAX || dp[n-1][amount] == INT_MAX-1) return -1;
    return dp[n-1][amount];
}

//Space Optimization
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev (amount+1);
    //Base Cases
    prev[0] = 0;
    for (int i=1; i<=amount; i++){
        if (i % coins[0] != 0) prev[i] = INT_MAX-1;
        else prev[i] = i/coins[0];
    }
    for (int i=1; i<n; i++){
        vector<int> curr (amount+1);
        for (int j=0; j<=amount; j++){
            int notPick = prev[j];
            int pick = INT_MAX-1;
            if (j >= coins[i]) pick = 1 + curr[j-coins[i]];
            curr[j] = min(pick, notPick);
        }
        prev = curr;
    }
    if (prev[amount] == INT_MAX || prev[amount] == INT_MAX-1) return -1;
    return prev[amount];
}

