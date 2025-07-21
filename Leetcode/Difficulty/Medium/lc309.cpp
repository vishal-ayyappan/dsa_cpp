#include <bits/stdc++.h>
using namespace std;

//Best Time to Buy and Sell Stock with Cooldown (When you sell, you have a cooldown)

//Recursive

// f(idx, canBeBought) --> max profit you can attain in the range (idx to n-1) given 'canBeBought' status.
int getMaxProfit(vector<int>& prices, int idx, int canBeBought){
    if (idx == prices.size()) return 0;
    //Base Case
    if (idx == prices.size()-1){
        if (canBeBought) return 0;
        else return prices[idx];
    }
    //Body
    //When you buy
    if (canBeBought){
        //You buy now
        int buyNow = -prices[idx] + getMaxProfit(prices, idx+1, 0);
        //You buy later
        int buyLater = getMaxProfit(prices, idx+1, 1);
        return max(buyNow, buyLater);
    }
    else{
        //You sell now
        int sellNow = prices[idx] + getMaxProfit(prices, idx+2, 1);
        //You sell Later
        int sellLater = getMaxProfit(prices, idx+1, 0);
        return max(sellNow, sellLater);
    }
}

int maxProfit(vector<int>& prices) {
    return getMaxProfit(prices, 0, 1);
}

//DP --> Memoization
int getMaxProfitDP(vector<int>& prices, int idx, int canBeBought, vector<vector<int>>& dp){
    //Base Cases
    if (idx == prices.size()) return 0;
    if (idx == prices.size()-1){
        if (canBeBought) return dp[idx][canBeBought] = 0;
        else return dp[idx][canBeBought] = prices[idx];
    }
    if (dp[idx][canBeBought] != -1) return dp[idx][canBeBought];
    //Body
    if (canBeBought){
        int buyNow = -prices[idx] + getMaxProfitDP(prices, idx+1, 0, dp);
        int buyLater = getMaxProfitDP(prices, idx+1, 1, dp);
        dp[idx][canBeBought] = max(buyNow, buyLater);
    }
    else{
        int sellNow = prices[idx] + getMaxProfitDP(prices, idx+2, 1, dp);
        int sellLater = getMaxProfitDP(prices, idx+1, 0, dp);
        dp[idx][canBeBought] = max(sellNow, sellLater);
    }
    return dp[idx][canBeBought];
}


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //Declare a DP matrix
    //dp[i][j] --> max profit you can attain from prices (idx to n-1) given status 'j'.
    vector<vector<int>> dp (n, vector<int> (2, -1));
    getMaxProfitDP(prices, 0, 1, dp);
    return dp[0][1];
}

//DP --> Tabulation


//DP --> Space Optimization
