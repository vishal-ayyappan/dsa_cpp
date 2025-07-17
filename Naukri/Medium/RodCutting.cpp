#include <bits/stdc++.h>
using namespace std;

//Rod cutting problem
int getmaxDP(vector<int>& price, int idx, int size, vector<vector<int>>& dp){
    //Base Case
    if (idx == 0){
        dp[idx][size] = price[idx]*size;
        return dp[idx][size];
    }
    if (dp[idx][size] != -1) return dp[idx][size];
    int notPick = getmaxDP(price, idx-1, size, dp);
    int pick = INT_MIN;
    if (size >= idx+1) pick = price[idx] + getmaxDP(price, idx, size-idx-1, dp);
    dp[idx][size] = max(pick, notPick);
    return dp[idx][size];
}

int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp (n, vector<int> (n+1, -1));
    //dp[i][j] --> maximum cost of selling a rod of length 'j', with the given prices in the range (0 to idx).
    getmaxDP(price, n-1, n, dp);
    return dp[n-1][n];
}