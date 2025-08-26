#include <bits/stdc++.h>
using namespace std;

//Coin Change
int getMinCoins(vector<int> &coins, vector<vector<int>>& dp, int i, int sum){
    //Base Case
    //If you get to the last coin
    if (i == 0){
        if (sum == 0) return 0;
        if (sum % coins[i] == 0){
            int nos = sum / coins[i];
            return dp[i][sum] = nos;
        }
        return dp[i][sum] = INT_MAX;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    //If you do not pick the coin
    int notPick = getMinCoins(coins, dp, i-1, sum);
    //If you pick the coin
    int pick = INT_MAX;
    if (sum >= coins[i]) pick = getMinCoins(coins, dp, i, sum-coins[i]);
    if (pick != INT_MAX) pick += 1;
    dp[i][sum] = min(pick, notPick);
    return dp[i][sum];
}

int minCoins(vector<int> &coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp (n, vector<int> (sum+1, -1));
    //dp[i][j] --> minimum coins needed to get to 'j' given you have coins from 0 to i
    getMinCoins(coins, dp, n-1, sum);
    if (dp[n-1][sum] == INT_MAX) return -1;
    return dp[n-1][sum];
}

//DP --> Tabulation
int minCoins(vector<int> &coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp (n, vector<int> (sum+1, INT_MAX));
    //dp[i][j] --> minimum coins needed to get to 'j' given you have coins from 0 to i
    //Base Case (You have to fill the first row)
    for (int target=0; target<=sum; target++){
        if (target % coins[0] == 0) dp[0][target] = target/coins[0];
    }
    for (int i=1; i<n; i++){
        for (int target=0; target<=sum; target++){
            int notPick = dp[i-1][target];
            int pick = INT_MAX;
            if (target >= coins[i] && dp[i][target - coins[i]] != INT_MAX) {
                pick = 1 + dp[i][target - coins[i]];
            }
            dp[i][target] = min(notPick, pick);
        }
    }
    if (dp[n-1][sum] == INT_MAX) return -1;
    return dp[n-1][sum];
}

