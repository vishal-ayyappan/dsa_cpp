#include <bits/stdc++.h>
using namespace std;

//Coin Change 2
//Find the number of combinations of denominations possible

//f(idx, amount) --> gives you the no of combinations of denominations in the range (0 to idx)
//that when added up equals target.
int getCountDP(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp){
    //Base Case
    if (idx == 0){
        if (amount % coins[idx] == 0) dp[idx][amount] = 1;
        else dp[idx][amount] = 0;
    }
    if (dp[idx][amount] != -1) return dp[idx][amount];
    int notPick = getCountDP(coins, idx-1, amount, dp);
    int pick = 0;
    if (amount >= coins[idx]) pick = getCountDP(coins, idx, amount-coins[idx], dp);
    dp[idx][amount] =  pick + notPick;
    return dp[idx][amount];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp (n, vector<int> (amount+1, -1));
    getCountDP(coins, n-1, amount, dp);
    return dp[n-1][amount];
}