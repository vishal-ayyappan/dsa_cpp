#include <bits/stdc++.h>
using namespace std;

// f(idx, target) --> no of ways you can get target from doing the required conditions. in the range (0 to idx)
int getWays(vector<int>& nums, int idx, int target){
    //Base Case
    if (idx == 0){
        if (-nums[idx] == target) return 1;
        if (nums[idx] == target) return 1;
        return 0;
    }
    int addOperation = getWays(nums, idx-1, target-nums[idx]);
    int subOperation = getWays(nums, idx-1, target+nums[idx]);
    return addOperation + subOperation;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return getWays(nums, n-1, target);
}


//DP --> Memoization
int getWaysDP(vector<int>& nums, int idx, int target, map<pair<int,int>, int>& dp){
    auto key = make_pair(idx, target);
    if (idx == 0){
        if (nums[idx] == 0 && target == 0) dp[key] = 2;
        else if (-nums[idx] == target) dp[key] = 1;
        else if (nums[idx] == target) dp[key] = 1;
        else dp[key] = 0;
        return dp[key];
    }
    if (dp.find(key) != dp.end()) return dp[key];
    int addOperation = getWaysDP(nums, idx-1, target-nums[idx], dp);
    int subOperation = getWaysDP(nums, idx-1, target+nums[idx], dp);
    dp[key] = addOperation + subOperation;
    return dp[key];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    map<pair<int,int>, int> dp;
    getWaysDP(nums, n-1, target, dp);
    auto key = make_pair(n-1, target);
    return dp[key];
}

//Cannot do Tabulation as it has -ve indices

//Another approach
// There is a bunch of elements you add and another bunch you subtract [So, it is similar to S1-S2 = target]

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), target);
    if (total%2 != 0 || total < 0) return 0;
    int targetSum = total/2;
    vector<vector<int>> dp (n, vector<int> (targetSum+1, 0));
    //Base Cases
    dp[0][0] = 1;
    if (nums[0] <= targetSum) dp[0][nums[0]] += 1;
    for (int i=1; i<n; i++){
        for (int j=0; j<=targetSum; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if (j >= nums[i]) pick = dp[i-1][j-nums[i]];
            dp[i][j] = pick + notPick;
        }
    }
    return dp[n-1][targetSum];
}