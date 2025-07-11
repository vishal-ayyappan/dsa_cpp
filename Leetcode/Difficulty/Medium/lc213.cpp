#include <bits/stdc++.h>
using namespace std;

//House Robber 2

//Houses are in circle
//If you pick 1, you cannot pick the house adjacent to the left and to the right
//Leave out the last element, and find max sum, you break the chain
//Leave out the first element and find max sum, you break the chain
//Why?? Because first and last can never be together.

//DP with memoization

int getMax(vector<int>& nums, int idx, vector<int>& dp){
    if (idx < 0) return 0;
    if (idx == 0){
        dp[idx] = nums[idx];
        return dp[idx];
    }
    if (dp[idx] != -1) return dp[idx];
    int pick = nums[idx] + getMax(nums, idx-2, dp);
    int notpick = getMax(nums, idx-1, dp);
    dp[idx] = max(pick, notpick);
    return dp[idx];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    //Removing the last element.
    vector<int> dp1 (n-1, -1);
    getMax(nums, n-2, dp1);
    //Removing the first element
    vector<int> nums_new;
    nums_new.assign(nums.begin()+1, nums.end());
    vector<int> dp2 (n-1, -1);
    getMax(nums_new, n-2, dp2);
    return max(dp1[n-2], dp2[n-2]);
}

//DP -> Tabulation method
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    //You run two for loops
    //Loop 1, exclude last element
    //1/ Create the dp array
    vector<int> dp1 (n-1, -1);
    //2/ Figure out the base case
    dp1[0] = nums[0];
    for (int i=1; i<n-1; i++){
        //3/ Do what you did in memoization
        int pick = nums[i];
        if (i>1) pick += dp1[i-2];
        int notPick = dp1[i-1];
        dp1[i] = max(pick, notPick);
    }
    //Loop 2, exclude first element
    vector<int> new_num;
    new_num.assign(nums.begin()+1, nums.end());
    //1/ Create the dp array
    vector<int> dp2 (n-1, -1);
    //2/ Figure out the base case
    dp2[0] = new_num[0];
    for (int i=1; i<new_num.size(); i++){
        //3/ Do what you did in memoization
        int pick = new_num[i];
        if (i>1) pick += dp2[i-2];
        int notPick = dp2[i-1];
        dp2[i] = max(pick, notPick);
    }
    return max(dp1.back(), dp2.back());
}

//With space optimization
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    //You run two for loops
    //Loop 1, exclude last element
    int prev1 = nums[0];
    int prev2 = 0;
    for (int i=1; i<n-1; i++){
        //3/ Do what you did in memoization
        int pick = nums[i];
        if (i>1) pick += prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    //Loop 2, exclude first element
    vector<int> new_num;
    new_num.assign(nums.begin()+1, nums.end());
    int nprev1 = new_num[0];
    int nprev2 = 0;
    for (int i=1; i<new_num.size(); i++){
        //3/ Do what you did in memoization
        int pick = new_num[i];
        if (i>1) pick += nprev2;
        int notPick = nprev1;
        int ncurr = max(pick, notPick);
        nprev2 = nprev1;
        nprev1 = ncurr;
    }
    return max(prev1, nprev1);
}

//TC - O(N)
//SC - O(N) --> for new_num vector
