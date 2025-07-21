#include <bits/stdc++.h>
using namespace std;

//Best Time to Buy and Sell Stock IV (You can do atmost K transactions)

//Recursive approach

//f(idx, canBeBought, cap) --> max profit given array (idx to n-1), given the status 'canBeBought' 
// given that you can do atmost 'cap' transactions.
int getMaxProfit(vector<int>& prices, int idx, int canBeBought, int cap){
    //Base Cases
    if (idx == prices.size()-1){
        if (canBeBought) return 0;
        else return prices[idx];
    }
    if (canBeBought){
        //If you buy now
        int profit1 = 0;
        if (cap > 0) profit1 = -prices[idx] + getMaxProfit(prices, idx+1, 0, cap-1);
        //If you buy later
        int profit2 = getMaxProfit(prices, idx+1, 1, cap);
        return max(profit1, profit2);
    }
    else{
        //You sell now
        int profit1 = prices[idx] + getMaxProfit(prices, idx+1, 1, cap);
        //You sell later
        int profit2 = getMaxProfit(prices, idx+1, 0, cap);
        return max(profit1, profit2);
    }
}

int maxProfit(int k, vector<int>& prices) {
    return getMaxProfit(prices, 0, 1, k);
}

//DP --> Memoization
int getMaxProfitDP(vector<int>& prices, int idx, int canBeBought, int cap, vector<vector<vector<int>>>& dp){
    //Base Cases
    if (idx == prices.size()-1){
        if (canBeBought) return dp[idx][canBeBought][cap] = 0;
        else return dp[idx][canBeBought][cap] = prices[idx];
    }
    if (dp[idx][canBeBought][cap] != -1) return dp[idx][canBeBought][cap];
    //If the status is 1
    if (canBeBought){
        //you buy now
        int profit1 = 0;
        if (cap > 0) profit1 = -prices[idx] + getMaxProfitDP(prices, idx+1, 0, cap-1, dp);
        //you buy later
        int profit2 = getMaxProfitDP(prices, idx+1, 1, cap, dp);
        dp[idx][canBeBought][cap] =  max(profit1, profit2);
    }
    //If the status is 0
    else{
        //You sell now
        int profit1 = prices[idx] + getMaxProfitDP(prices, idx+1, 1, cap, dp);
        //You sell later
        int profit2 = getMaxProfitDP(prices, idx+1, 0, cap, dp);
        dp[idx][canBeBought][cap] =  max(profit1, profit2);
    }
    return dp[idx][canBeBought][cap];
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    //Declare DP array
    //dp[i][j][k] --> max profit you get in the array prices (i to n-1) given you can make atmost 'k' transactions
    // and you have 'j' (can/cannot be bought status).
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (k+1, -1)));
    getMaxProfitDP(prices, 0, 1, k, dp);
    return dp[0][1][k];
}

//DP --> Tabulation
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    //Declare DP array
    //dp[i][j][k] --> max profit you get in the array prices (i to n-1) given you can make atmost 'k' transactions
    // and you have 'j' (can/cannot be bought status).
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (k+1, -1)));
    //Base Cases
    for (int cap=0; cap<=k; cap++){
        //if you cannot buy
        dp[n-1][0][cap] = prices[n-1];
        //If you can buy
        dp[n-1][1][cap] = 0;
    }
    //Body
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<2; j++){
            for (int cap=0; cap<=k; cap++){
                //If it can be bought
                if (j == 1){
                    //You buy now
                    int profit1 = 0;
                    if (cap > 0) profit1 = -prices[i] + dp[i+1][0][cap-1];
                    //You buy later
                    int profit2 = dp[i+1][1][cap];
                    dp[i][j][cap] = max(profit1, profit2);
                }
                //Else
                else{
                    //You sell now
                    int profit1 = prices[i] + dp[i+1][1][cap];
                    //You sell later
                    int profit2 = dp[i+1][0][cap];
                    dp[i][j][cap] = max(profit1, profit2);
                }
            }
        }
    }
    return dp[0][1][k];
}

