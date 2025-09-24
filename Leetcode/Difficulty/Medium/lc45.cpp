#include <bits/stdc++.h>
using namespace std;

//Jump Game 2 (Try all ways)
//Classical DP

int getMinSteps(vector<int>& nums, int i, vector<int>& dp){
    if (i == nums.size()-1) return dp[i] = 0;
    int can_move_by = nums[i];
    if (can_move_by == 0) return dp[i] = INT_MAX;
    if (dp[i] != -1) return dp[i];
    int mini = INT_MAX;
    for (int j=1; j<=can_move_by; j++){
        if (i + j >= nums.size()) continue;
        int steps = getMinSteps(nums, i+j, dp);
        if (steps != INT_MAX) steps += 1;
        mini = min(mini, steps);
    }
    return dp[i] = mini;
}

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp (n, -1);
    //dp[i] --> min steps to reach from i to n-1
    getMinSteps(nums, 0, dp);
    return dp[0];
}