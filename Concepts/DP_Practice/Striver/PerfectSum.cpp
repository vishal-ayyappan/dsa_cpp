#include <bits/stdc++.h>
using namespace std;

//Perfect Sum Problem
int getCount(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
    //Base Case
    if (i == 0){
        if (target == 0 && arr[0] == 0) return dp[0][target] = 2;
        if (target == 0 || target == arr[0]) return dp[0][target] = 1;
        return 0;
    }
    if (dp[i][target] != -1) return dp[i][target];
    //Write the recurrence relation
    //You either pick or you dont
    int notPick = getCount(arr, dp, i-1, target);
    int pick = 0;
    if (target - arr[i] >= 0) pick = getCount(arr, dp, i-1, target-arr[i]);
    dp[i][target] = pick + notPick;
    return dp[i][target];
}

int perfectSum(vector<int>& arr, int target) {
    //Count all subsets
    int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (target+1, -1));
    // dp[i][j] --> Count all subsets from 0 to i, given target j
    return getCount(arr, dp, n-1, target);
}

//DP --> Tabulation
int perfectSum(vector<int>& arr, int target) {
    //Count all subsets
    int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (target+1, 0));
    // dp[i][j] --> Count all subsets from 0 to i, given target j
    //Write the base case
    dp[0][0] = 1;
    if (arr[0] <= target) dp[0][arr[0]] += 1;
    for (int i=1; i<n; i++){
        for (int j=0; j<=target; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if (j - arr[i] >= 0) pick += dp[i-1][j-arr[i]];
            dp[i][j] = pick + notPick;
        }
    }
    return dp[n-1][target];
}


