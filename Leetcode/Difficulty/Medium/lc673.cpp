#include <bits/stdc++.h>
using namespace std;

//Number of Longest Increasing Subsequence

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    //Get the LIS table
    vector<int> dp (n, 1);
    vector<int> cnt (n, 1);
    int maxLen = 1;
    int lastIdx = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (nums[i] > nums[j]){
                int length = 1 + dp[j];
                if (length > dp[i]){
                    dp[i] = length;
                    cnt[i] = cnt[j];
                }
                else if (length == dp[i]){
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
        }
    }
    int ans = 1;
    for (int i=0; i<n; i++){
        if (dp[i] == maxLen) ans += cnt[i];
    }
    return ans;
}