#include <bits/stdc++.h>
using namespace std;

//Best Time to Buy and Sell Stock III

//f(idx, canBeBought, cap) --> max Profit you can get in the range (idx to n-1) given the liberty to buy/notBuy, 
// given that you can make 'cap' no of transactions
int getMaxProfit(vector<int>& prices, int idx, int canBeBought, int cap){
    //Base Cases
    if (idx == prices.size()-1){
        if (canBeBought) return 0;
        else return prices[idx];
    }
    //If you can buy
    if (canBeBought){
        //If you buy now
        int profit1 = 0;
        if (cap > 0){
            profit1 = -prices[idx] + getMaxProfit(prices, idx+1, 0, cap-1);
        }
        //If you buy later
        int profit2 = getMaxProfit(prices, idx+1, 1, cap);
        return max(profit1, profit2);
    }
    //If you can sell
    else{
        //If you sell now
        int profit1 = prices[idx] + getMaxProfit(prices, idx+1, 1, cap);
        //If you sell later
        int profit2 = getMaxProfit(prices, idx+1, 0, cap);
        return max(profit1, profit2);
    }
}

int maxProfit(vector<int>& prices) {
    return getMaxProfit(prices, 0, 1, 2);
}

//DP --> Memoization
int getMaxProfitDP(vector<int>& prices, int idx, int canBeBought, int cap, vector<vector<vector<int>>>& dp){
    //Base Cases
    if (idx == prices.size()-1){
        if (canBeBought) return dp[idx][canBeBought][cap] = 0;
        else return dp[idx][canBeBought][cap] = prices[idx];
    }
    if (dp[idx][canBeBought][cap] != -1) return dp[idx][canBeBought][cap];
    if (canBeBought){
        //You buy now
        int profit1 = 0;
        if (cap > 0) profit1 = -prices[idx] + getMaxProfitDP(prices, idx+1, 0, cap-1, dp);
        //You buy later
        int profit2 = getMaxProfitDP(prices, idx+1, 1, cap, dp);
        dp[idx][canBeBought][cap] = max(profit1, profit2);
    }
    else{
        //You sell now
        int profit1 = prices[idx] + getMaxProfitDP(prices, idx+1, 1, cap, dp);
        //You sell later
        int profit2 = getMaxProfitDP(prices, idx+1, 0, cap, dp);
        dp[idx][canBeBought][cap] = max(profit1, profit2);
    }
    return dp[idx][canBeBought][cap];
}

int maxProfit(vector<int>& prices) {
    //Declare a DP array
    int n = prices.size();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (3, -1)));
    //dp[i][j][k] --> max profit you can get in the range (i to n-1) given the liberty to 'j' and given that you can
    //do atmost k transactions
    getMaxProfitDP(prices, 0, 1, 2, dp);
    return dp[0][1][2];
}


//DP --> Tabulation
int maxProfit(vector<int>& prices) {
    //Declare a DP array
    int n = prices.size();
    //dp[i][j][k] --> max profit you can get in the range (i to n-1) given the liberty to 'j' and given that you can
    //do atmost k transactions
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (3, -1)));
    //Base Cases
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            if (i == 1) dp[n-1][i][j] = 0;
            else dp[n-1][i][j] = prices[n-1];
        }
    }
    //Body
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<2; j++){
            for (int k=0; k<3; k++){
                if (j == 1){
                    //You buy now
                    int profit1 = 0;
                    if (k > 0) profit1 = -prices[i] + dp[i+1][0][k-1];
                    //You buy later
                    int profit2 = dp[i+1][1][k];
                    dp[i][j][k] = max(profit1, profit2);
                }
                else{
                    //You sell now
                    int profit1 = prices[i] + dp[i+1][1][k];
                    //You sell later
                    int profit2 = dp[i+1][0][k];
                    dp[i][j][k] = max(profit1, profit2);

                }
            }
        }
    }
    return dp[0][1][2];
}


//Space Optimization
int maxProfit(vector<int>& prices) {
    //Declare a DP array
    int n = prices.size();
    vector<vector<int>> dp (2, vector<int> (3, -1));
    //Base Cases
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            if (i == 1) dp[i][j] = 0;
            else dp[i][j] = prices[n-1];
        }
    }
    //Body
    for (int i=n-2; i>=0; i--){
        vector<vector<int>> curr (2, vector<int> (3, -1));
        for (int j=0; j<2; j++){
            for (int k=0; k<3; k++){
                if (j == 1){
                    //You buy now
                    int profit1 = 0;
                    if (k > 0) profit1 = -prices[i] + dp[0][k-1];
                    //You buy later
                    int profit2 = dp[1][k];
                    curr[j][k] = max(profit1, profit2);
                }
                else{
                    //You sell now
                    int profit1 = prices[i] + dp[1][k];
                    //You sell later
                    int profit2 = dp[0][k];
                    curr[j][k] = max(profit1, profit2);

                }
            }
        }
        dp = curr;
    }
    return dp[1][2];
}