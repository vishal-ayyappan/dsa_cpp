#include <bits/stdc++.h>
using namespace std;

//House Robber

//DP --> Memo

int getMaxMoney(vector<int>& nums, int i, vector<int>& dp){
    //Base Case
    //If it goes out of bounds
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];
    //Write the recurrence relation
    //If you do not pick, you can pick at the next house
    int notPick = getMaxMoney(nums, i-1, dp);
    //If you pick
    int pick = nums[i] + getMaxMoney(nums, i-2, dp);
    dp[i] = max(pick, notPick);
    return dp[i];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp (n, -1);
    // dp[i] --> max money you can get given you have 0 to i houses
    getMaxMoney(nums, n-1, dp);
    return dp[n-1];
}

//DP --> Tabulation

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp (n, -1);
    // dp[i] --> max money you can get given you have 0 to i houses
    //Base Case
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i=2; i<n; i++){
        int notPick = dp[i-1];
        int pick = 0;
        if (i > 1) pick = nums[i] + dp[i-2];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}

