#include <bits/stdc++.h>
using namespace std;

int getMinEnergy(vector<int> &heights, int i, vector<int>& dp){
    //If it is the first index
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    //Get the min energy
    int oneStep = getMinEnergy(heights, i-1, dp) + abs(heights[i] - heights[i-1]);
    int twoStep = INT_MAX;
    if (i > 1) twoStep = getMinEnergy(heights, i-2, dp) + abs(heights[i] -  heights[i-2]);
    dp[i] = min(oneStep, twoStep);
    return dp[i];
}

int frogJump(int n, vector<int> &heights){
    //You can go either 1 or 2 steps
    vector<int> dp (n, -1);
    getMinEnergy(heights, n-1, dp);
    //Minimum energy needed to go from 0 to i.
    return dp[n-1];
}


//DP --> Tabulation
int frogJump(int n, vector<int> &heights){
    //Declare a DP array
    vector<int> dp (n, -1);
    //Write the base case
    dp[0] = 0;
    //Do what you did in recursion
    for (int i=1; i<n; i++){
        int oneStep = abs(heights[i]-heights[i-1]) + dp[i-1];
        int twoStep = INT_MAX;
        if (i > 1) twoStep = abs(heights[i]-heights[i-2]) + dp[i-2];
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n-1];
}

