#include <bits/stdc++.h>
using namespace std;

//Longest Increasing Subsequence

//DP --> Memoization
int getLIS(vector<int>& nums, int idx, int prevLargestIdx, vector<vector<int>>& dp){
    //Base cases
    if (idx == 0){
        if (prevLargestIdx == nums.size() || nums[idx] < nums[prevLargestIdx]) return dp[idx][prevLargestIdx] = 1;
        else return dp[idx][prevLargestIdx] = 0;
    }
    if (dp[idx][prevLargestIdx] != -1) return dp[idx][prevLargestIdx];
    //Body
    int notPick = getLIS(nums, idx-1, prevLargestIdx, dp);
    int pick = 0;
    if (prevLargestIdx == nums.size() || nums[idx] < nums[prevLargestIdx]){
        pick = 1 + getLIS(nums, idx-1, idx, dp);
    }
    return dp[idx][prevLargestIdx] = max(pick, notPick);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //Create a DP array
    //dp[i][j] --> LI subsequence of nums (0 to i) given the prev largest is nums[j+1]. Initially, there is no largest element
    vector<vector<int>> dp (n, vector<int> (n+1, -1));
    getLIS(nums, n-1, n, dp);
    return dp[n-1][n];
}

//DP --> Tabulation
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //Create a DP array
    //dp[i][j] --> LI subsequence of nums (0 to i) given the prev largest is nums[j+1]. Initially, there is no largest element
    vector<vector<int>> dp (n, vector<int> (n+1, 0));  
    //Base case
    dp[0][n] = 1;
    for (int i=0; i<n; i++){
        if (nums[0] < nums[i]) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    //Body
    for (int i=1; i<n; i++){
        for (int j=0; j<=n; j++){
            if (j > i){
                int notPick = dp[i-1][j];
                int pick = 0;
                if (j == n || nums[i] < nums[j]) pick = 1 + dp[i-1][i];
                dp[i][j] = max(pick, notPick);
            } 
        }
    }
    return dp[n-1][n];
}

//You can further Space Optimize it
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //Create a DP array
    //dp[i][j] --> LI subsequence of nums (0 to i) given the prev largest is nums[j+1]. Initially, there is no largest element
    vector<int> dp (n+1);  
    //Base case
    dp[n] = 1;
    for (int i=0; i<n; i++){
        if (nums[0] < nums[i]) dp[i] = 1;
    }
    //Body
    for (int i=1; i<n; i++){
        vector<int> curr (n+1);
        for (int j=0; j<=n; j++){
            if (j > i){
                int notPick = dp[j];
                int pick = 0;
                if (j == n || nums[i] < nums[j]) pick = 1 + dp[i];
                curr[j] = max(pick, notPick);
            } 
        }
        dp = curr;
    }
    return dp[n];
}



//Another approach
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //Initialize it with one
    vector<int> dp (n, 1);
    //dp[i] --> represents LIS that ends with i;
    for (int i=0; i<n; i++){
        int value = dp[i];
        for (int j=0; j<i; j++){
            if (nums[i] > nums[j]){
                int newValue = value + dp[j];
                dp[i] = max(dp[i], newValue);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

