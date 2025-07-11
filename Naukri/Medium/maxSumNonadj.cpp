#include <bits/stdc++.h> 
using namespace std; 

//DP (Memoization)

int getMaxSum(vector<int> &nums, int idx, vector<int>& dp){
    if (dp[idx] != -1) return dp[idx];
    if (idx == nums.size()-1) {
        dp[idx] = nums[idx];
        return dp[idx];
    }
    //Adjacent element is not taken into account
    int maxi = nums[idx];
    for (int i=idx+2; i<nums.size(); i++){
        int value = INT_MIN;
        if (i < nums.size()) value = getMaxSum(nums, i, dp) + nums[idx];
        maxi = max(value, maxi);
    }
    dp[idx] = maxi;
    return dp[idx];
}

int maximumNonAdjacentSum(vector<int> &nums){
    //Start from the first index
    int n = nums.size();
    vector<int> dp (n, -1);
    for (int i=0; i<n; i++){
        if (dp[i] == -1) getMaxSum(nums, i, dp);
    }
    int maxSum = dp[0];
    for (int i=1; i<dp.size(); i++){
        if (dp[i] > maxSum) maxSum = dp[i];
    }
    return maxSum;
}

//TC - O(N*N)

//Better approach (Use the logic of print subsequences) [Pick and Not Pick]

//Using Recursion
int getSum(vector<int> &nums, int idx){
    if (idx == 0) return nums[idx];
    if (idx < 0) return 0;
    //We do not take adjacent
    int pick = nums[idx] + getSum(nums, idx-2);
    //Element adjacent to the index
    int notPick = getSum(nums, idx-1);
    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return getSum(nums, n-1);
}

//DP with memoization (Each index will have the maxsum, when starting from that element)
//The DP array represents, the maximum sum for each size.

int getSumDP(vector<int>& nums, int idx, vector<int>& dp){
    if (idx < 0) return 0;
    if (idx == 0) return nums[idx];
    if (dp[idx] != -1) return dp[idx];
    int pick = nums[idx] + getSumDP(nums, idx-2, dp);
    int notpick = getSumDP(nums, idx-1, dp);
    dp[idx] = max(pick, notpick);
    return dp[idx];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp (n, -1);
    getSumDP(nums, n-1, dp);
    return dp[n-1];
}

//TC - O(N)
//SC - O(N) + O(N)


//DP (Tabulation)
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if (n == 1) return nums[0];
    //Declaring a DP array
    vector<int> dp (n, -1);
    //Base Case
    dp[0] = nums[0];
    for (int i=1; i<n; i++){
        int pick = nums[i];
        if (i > 1) pick += dp[i-2]; 
        int notpick = dp[i-1];
        dp[i] = max(pick, notpick);
    }
    return dp[n-1]; 
}

//TC - O(N)
//SC - O(N)

//Space optimizing
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if (n == 1) return nums[0];
    //Base Case
    //You only need 2 variables
    int prev1 = nums[0];
    int prev2 = 0;
    for (int i=1; i<n; i++){
        int pick = nums[i];
        if (i > 1) pick += prev2; 
        int notpick = prev1;
        int curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

//TC - O(N)
//SC - O(1)




