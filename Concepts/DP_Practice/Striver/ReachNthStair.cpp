#include <bits/stdc++.h>
using namespace std;

//Ways to Reach the n'th Stair

int getWays(int i, vector<int>& dp){
    //If you reach the 1st step, you return
    if (i == 0) return 1;
    if (dp[i] != -1) return dp[i];
    //Count all the steps
    //He either climbs 1 or 2
    int oneStep = getWays(i-1, dp);
    int twoStep = 0;
    if (i > 1) twoStep += getWays(i-2, dp);
    dp[i] = oneStep + twoStep;
    return dp[i];
}

int countWays(int n) {
    //Count all the ways
    vector<int> dp (n+1, -1);
    //dp[i] --> no of ways to reach from 1 to i;
    getWays(n, dp);
    return dp[n];
}

//Tabulation (Bottom up)
int countWays(int n) {
    //Count all the ways
    vector<int> dp (n+1, -1);   
    //This is bottom up
    dp[0] = 1;
    for (int i=1; i<=n; i++){
        //Either you go one step or two steps
        int oneStep = dp[i-1];
        int twoStep = 0;
        if (i > 1) twoStep = dp[i-2];
        dp[i] = oneStep + twoStep;
    }
    return dp[n];
}

//Space Optimization
int countWays(int n) {
    //Count all the ways
    vector<int> dp (n+1, -1);   
    //This is bottom up
    dp[0] = 1;
    int prev1 = 1;
    int prev2 = 1;
    for (int i=1; i<=n; i++){
        //Either you go one step or two steps
        int oneStep = prev1;
        int twoStep = 0;
        if (i > 1) twoStep = prev2;
        prev1 = oneStep + twoStep;
        prev2 = oneStep;
    }
    return prev1;
}
