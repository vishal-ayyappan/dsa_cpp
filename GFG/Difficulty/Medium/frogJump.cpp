#include <bits/stdc++.h>
using namespace std;

//Representing the question in terms of indexes

//Top Down Approach (Memoization)

int minimumCost(vector<int>& height, int idx, vector<int>& dp){
    if (idx == height.size()-1) return 0;
    if (dp[idx] != -1) return dp[idx];
    int onestep = minimumCost(height, idx+1, dp) + abs(height[idx+1] - height[idx]);
    int twostep = INT_MAX;
    if (idx < height.size()-2) twostep = minimumCost(height, idx+2, dp) + abs(height[idx+2] - height[idx]);
    dp[idx] =  min(onestep, twostep);
    return dp[idx];
}

int minCost(vector<int>& height) {
    int n = height.size();
    vector<int> dp (n, -1);
    return minimumCost(height, 0, dp);
    return dp[n-1];
}

//Bottom up approach (Tabulation)

int minCost(vector<int>& height) {
    int n = height.size();
    vector<int> dp (n, -1);
    //Put the base cases in
    dp[0] = 0;
    for (int i=1; i<n; i++){
        //Do the steps you did in recursion
        int first = dp[i-1] + abs(height[i] - height[i-1]);
        int second = INT_MAX;
        if (i > 1) second = dp[i-2] + abs(height[i] - height[i-2]);
        dp[i] = min(first, second);
    }
    return dp[n-1];
}

//Space optimization after tabulation

int minCost(vector<int>& height) {
    int n = height.size();
    //Put the base cases in
    int prev1 = 0;
    int prev2 = 0;
    for (int i=1; i<n; i++){
        //Do the steps you did in recursion
        int first = prev1 + abs(height[i] - height[i-1]);
        int second = INT_MAX;
        if (i > 1) second = prev2 + abs(height[i] - height[i-2]);
        int curr = min(first, second);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


