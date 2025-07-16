#include <bits/stdc++.h>
using namespace std;

//Partition equal to subset sum 
//The subset sum should be S/2 if there can be partition

bool getSum(vector<int>& nums, int idx, int target){
    //Base Cases
    if (target == 0) return true;
    if (idx == 0){
        if (nums[0] == target) return true;
        return false;
    }
    bool notPick = getSum(nums, idx-1, target);
    bool pick = false;
    if (target >= nums[idx]) pick = getSum(nums, idx-1, target-nums[idx]);
    return (pick || notPick);
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i=0; i<n; i++) sum += nums[i];
    if (sum%2 == 1) return false;
    int target = sum/2;
    //Check all possible ways
    //f(i, target) will tell you if there exist a subsequence from (0 to i) with the remainig target.
    return getSum(nums, n-1, target);
}

//DP --> Memoization
int getSumDP(vector<int>& nums, int idx, int target, vector<vector<int>>& dp){
    //Base Cases
    if (target < 0) return 0;
    if (dp[idx][target] != -1) return dp[idx][target];
    if (target == 0){
        dp[idx][target] = 1;
        return dp[idx][target];
    }
    if (idx == 0){
        if (nums[idx] == target) dp[idx][target] = 1;
        else dp[idx][target] = 0;
        return dp[idx][target];
    }
    int notPick = getSumDP(nums, idx-1, target, dp);
    int pick = getSumDP(nums, idx-1, target-nums[idx], dp);
    dp[idx][target] = (pick || notPick);
    return dp[idx][target];
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i=0; i<n; i++) sum += nums[i];
    if (sum%2 == 1) return false;
    int target = sum/2;
    //Declare a DP matrix
    //dp[i][target] will tell you if there exists a subsequence from (0 to i) with sum == target
    vector<vector<int>> dp (n, vector<int> (target+1, -1));
    getSumDP(nums, n-1, target, dp);
    return dp[n-1][target];
}

//TC - O(N*M) + O(N)
//SC - O(N*M) + O(N)--> Recursion stack space


//DP--> Tabulation
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i=0; i<n; i++) sum += nums[i];
    if (sum%2 == 1) return false;
    int target = sum/2;
    //Declare a DP matrix
    //dp[i][target] will tell you if there exists a subsequence from (0 to i) with sum == target
    vector<vector<bool>> dp (n, vector<bool> (target+1, false));
    //Base Cases
    //Whenever the remaining target is 0 you return 0.
    for (int i=0; i<n; i++) dp[i][0] = true;
    //When the first index value equals target
    dp[0][nums[0]] = true;
    for (int i=1; i<n; i++){
        for (int j=1; j<=target; j++){
            bool notPick = dp[i-1][j];
            bool pick = false;
            if (j > nums[i]) pick = dp[i-1][j-nums[i]];
            dp[i][j] = (pick || notPick);
        }
    }
    return dp[n-1][target];
}


//Space Optimization
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i=0; i<n; i++) sum += nums[i];
    if (sum%2 == 1) return false;
    int target = sum/2;
    //Declare a DP matrix
    //dp[i][target] will tell you if there exists a subsequence from (0 to i) with sum == target
    vector<vector<bool>> dp (n, vector<bool> (target+1, false));
    vector<bool> prev (target+1, false);
    prev[0] = true;
    //If nums[0] > target, it will result in out of bounds error
    if (nums[0] <= target) prev[nums[0]] = true;
    for (int i=1; i<n; i++){
        vector<bool> curr (target+1, false);
        curr[0] = true;
        for (int j=1; j<=target; j++){
            bool notPick = prev[j];
            bool pick = false;
            if (j > nums[i]) pick = prev[j-nums[i]];
            curr[j] = (pick || notPick);
        }
        prev = curr;
    }
    return prev[target];
}