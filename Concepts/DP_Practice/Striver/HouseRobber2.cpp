#include <bits/stdc++.h>
using namespace std;

//House Robber II

long long int getMaxLoot(vector<int>& nums, int i, vector<long long int>& dp){
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];
    //Do the recursive calls
    long long int notpick = getMaxLoot(nums, i-1, dp);
    long long int pick = nums[i] + getMaxLoot(nums, i-2, dp);
    dp[i] = max(pick, notpick);
    return dp[i];
}

long long int getMax(vector<int>& nums){
    int n = nums.size();
    vector<long long int> dp (n, -1);
    //dp[i] --> max loot you can get from 0 to i
    getMaxLoot(nums, n-1, dp);
    return dp[n-1];
}

long long int houseRobber(vector<int>& valueInHouse){
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];
    if (n == 2) return max(valueInHouse[0], valueInHouse[1]);
    vector<int> case1 (valueInHouse.begin(), valueInHouse.end()-1);
    vector<int> case2 (valueInHouse.begin()+1, valueInHouse.end());
    long long max1 = getMax(case1);
    long long max2 = getMax(case2);
    return max(max1, max2);
}