#include <bits/stdc++.h>
using namespace std;

//Best Time to Buy and Sell Stock II

//Recursion
//Try all possible ways (Keep an account of whether it is previosly bought or no)

//f(idx, bought) --> maximum profit you can get from prices (idx to n-1) given the status of bought/notBought
int getMaxProfit(vector<int>& prices, int idx, bool canBeBought){
    //Base Cases
    if (idx == prices.size()-1){
        //If it canBeBought == 1, 
        if (canBeBought) return 0;
        else return prices[idx];
    }
    //Recursive Calls
    if (canBeBought){
        //You buy it.
        int profit1 = -prices[idx] + getMaxProfit(prices, idx+1, false);
        //You do not buy it
        int profit2 = getMaxProfit(prices, idx+1, true);
        return max(profit1, profit2);
    }
    else{
        //You sell it
        int profit1 = prices[idx] + getMaxProfit(prices, idx+1, true);
        //You do not sell it
        int profit2 = getMaxProfit(prices, idx+1, false);
        return max(profit1, profit2);
    }
}

int maxProfit(vector<int>& prices) {
    return getMaxProfit(prices, 0, true);
}

//DP --> Memoization
int getMaxProfitDP(vector<int>& prices, int idx, int canBeBought, vector<vector<int>>& dp){
    if (idx == prices.size()-1){
        if (canBeBought) dp[idx][canBeBought] = 0;
        else dp[idx][canBeBought] = prices[idx];
        return dp[idx][canBeBought];
    }
    if (dp[idx][canBeBought] != -1) return dp[idx][canBeBought];
    if (canBeBought){
        int profit1 = -prices[idx] + getMaxProfitDP(prices, idx+1, 0, dp);
        int profit2 = getMaxProfitDP(prices, idx+1, 1, dp);
        dp[idx][canBeBought] = max(profit1, profit2);
    }
    else{
        int profit1 = prices[idx] + getMaxProfitDP(prices, idx+1, 1, dp);
        int profit2 = getMaxProfitDP(prices, idx+1, 0, dp);
        dp[idx][canBeBought] = max(profit1, profit2);
    }
    return dp[idx][canBeBought];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //Declare a DP array
    vector<vector<int>> dp (n, vector<int> (2, -1));
    getMaxProfitDP(prices, 0, 1, dp);
    return dp[0][1];
}

//DP --> Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //Declare a DP array
    vector<vector<int>> dp (n, vector<int> (2, -1));
    //Declare the Base Cases
    dp[n-1][1] = 0;
    dp[n-1][0] = prices[n-1];
    for (int i=n-2; i>=0; i--){
        //You can buy
        int buy1 = -prices[i] + dp[i+1][0];
        int buy2 = dp[i+1][1];
        dp[i][1] = max(buy1, buy2);
        //You can sell
        int sell1 = prices[i] + dp[i+1][1];
        int sell2 = dp[i+1][0];
        dp[i][0] = max(sell1, sell2);
    }
    return dp[0][1];
}

//Space Optimization
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //Declare a DP array
    vector<int> dp (2, 0);
    //Declare the Base Cases
    dp[1] = 0;
    dp[0] = prices[n-1];
    for (int i=n-2; i>=0; i--){
        //You can buy
        vector<int> curr (2);
        int buy1 = -prices[i] + dp[0];
        int buy2 = dp[1];
        curr[1] = max(buy1, buy2);
        //You can sell
        int sell1 = prices[i] + dp[1];
        int sell2 = dp[0];
        curr[0] = max(sell1, sell2);
        dp = curr;
    }
    return dp[1];
}



