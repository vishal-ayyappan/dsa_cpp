#include <bits/stdc++.h>
using namespace std;

//DP with memoization (Top Down)

int minCost(vector<int>& height, int idx, int k, vector<int>& dp){
    //Base Case
    if (idx == 0) return 0;
    if (dp[idx] != -1) return dp[idx];
    int mini = INT_MAX;
    for (int i=1; i<=k; i++){
        int kstep = INT_MAX;
        if (idx - i >= 0) kstep = minCost(height, idx-i, k, dp) + abs(height[idx] - height[idx-i]);
        mini = min(mini, kstep);
    }
    dp[idx] = mini;
    return dp[idx];
}

int minimizeCost(int n, int k, vector<int> &height){
    if (n == 1) return 0;
    vector<int> dp (n,-1);
    minCost(height, n-1, k, dp);
    return dp[n-1];
}

//DP Tabulation (Bottom up approach)
int minimizeCost(int n, int k, vector<int> &height){
    //1 Initialize the same dp array
    vector<int> dp (n, -1);
    //2 As it is Bottom Up, find out the base cases
    dp[0] = 0;
    //3 Do whatever you did in recursion
    for (int i=1; i<n; i++){
        int mini = INT_MAX;
        for (int j=1; j<=k; j++){
            if (i-j >= 0){
                int kstep = dp[i-j] + abs(height[i] - height[i-j]);
                mini = min(mini, kstep);
            }
        }
        dp[i] = mini;
    }
    return dp[n-1];
}

//TC - O(N*K)
//SC - O(N)

//We cannot optimize space in here