#include <bits/stdc++.h>
using namespace std;

//Largest Divisible Subset (Can only be solved if the array is sorted)
// If (arr[1] % arr[0] == 0, then if arr[2] % arr[1] == 0, then arr[2] is divisible by arr[0] as well)

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    //Sort the array first
    sort(nums.begin(), nums.end());
    vector<int> dp (n, 1);
    vector<int> hash (n);
    int maxi = 1;
    int endIndex = 0;
    for (int i=0; i<n; i++){
        hash[i] = i;
        for (int j=0; j<i; j++){
            if (nums[i] % nums[j] == 0){
                int value = 1 + dp[j];
                dp[i] = max(value, dp[i]);
                if (dp[i] == value) hash[i] = j;
            }
        }
        if (dp[i] > maxi){
            maxi = dp[i];
            endIndex = i;
        }
    }
    //BackTracking to get the result
    vector<int> ans;
    ans.push_back(nums[endIndex]);
    while (hash[endIndex] != endIndex){
        endIndex = hash[endIndex];
        ans.push_back(nums[endIndex]);
    }
    return ans;
}