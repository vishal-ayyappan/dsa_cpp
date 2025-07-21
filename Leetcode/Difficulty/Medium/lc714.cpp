#include <bits/stdc++.h>
using namespace std;

//Best Time to Buy and Sell Stock with Transaction Fee
//When you sell, you deduct the transaction fee

int getMaxProfit(vector<int>& prices, int idx, int canBeBought, vector<vector<int>>& dp, int fee){
    //Base Case
    if (idx == prices.size()-1){
        if (canBeBought) return dp[idx][canBeBought] = 0;
        else return dp[idx][canBeBought] = prices[idx];
    }
    if (dp[idx][canBeBought] != -1) return dp[idx][canBeBought];
    //Buy
    if (canBeBought){
        int buyNow = -prices[idx] - fee + getMaxProfit(prices, idx+1, 0, dp, fee);
        int buyLater = getMaxProfit(prices, idx+1, 1, dp, fee);
        dp[idx][canBeBought] = max(buyNow, buyLater);
    }
    else{
        int sellNow = prices[idx] + getMaxProfit(prices, idx+1, 1, dp, fee);
        int sellLater = getMaxProfit(prices, idx+1, 0, dp, fee);
        dp[idx][canBeBought] = max(sellNow, sellLater);
    }
    return dp[idx][canBeBought];
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    //Create a DP array
    vector<vector<int>> dp (n, vector<int> (2, -1));
    getMaxProfit(prices, 0, 1, dp, fee);
    return dp[0][1];
}