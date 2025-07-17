#include <bits/stdc++.h>
using namespace std;


const int mod = 1e9 + 7;
int getCount(int nStairs, vector<int>& dp){
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;
    if (dp[nStairs] != -1) return dp[nStairs];
    int oneStep = getCount(nStairs-1, dp);
    int twoStep = getCount(nStairs-2, dp);
    dp[nStairs] = (oneStep + twoStep)%mod;
    return dp[nStairs];
}

int countDistinctWays(int nStairs) {
    //You can either move one or two steps
    if (nStairs == 0) return 1;
    vector<int> dp (nStairs+1, -1);
    //dp[stairs] represents the no of ways you can go from 0 to stairs
    getCount(nStairs, dp);
    return dp[nStairs];
}

//DP - Tabulation
const int mod = 1e9 + 7;
int countDistinctWays(int nStairs) {
    //You can either move one or two steps
    if (nStairs == 0) return 1;
    vector<int> dp (nStairs+1, -1);
    //dp[stairs] represents the no of ways you can go from 0 to stairs
    //Base Case
    dp[0] = 1;
    for (int i=1; i<=nStairs; i++){
        int oneStep = dp[i-1];
        int twoStep = 0;
        if (i > 1) twoStep = dp[i-2];
        dp[i] = (oneStep + twoStep)%mod;
    }
    return dp[nStairs];
}


//Space Optimization
const int mod = 1e9 + 7;
int countDistinctWays(int nStairs) {
    //You can either move one or two steps
    if (nStairs == 0) return 1;
    int prev1 = 1;
    int prev2 = 0;
    for (int i=1; i<=nStairs; i++){
        int oneStep = prev1;
        int twoStep = 0;
        if (i > 1) twoStep = prev2;
        int curr = (oneStep + twoStep)%mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

