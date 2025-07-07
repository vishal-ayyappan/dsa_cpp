#include <bits/stdc++.h>
using namespace std;

//No of subarrays with sum at most K - no of subarrays with sum at most K-1

int noOfSubarrays(vector<int>& nums, int goal){
    int n = nums.size();
    int left = 0;
    int right = 0;
    int count = 0;
    int sum = 0;
    while (right < n){
        sum += nums[right];
        while (sum > goal){
            sum -= nums[left];
            left++;
        }
        if (sum <= goal){
            count += right - left + 1;
        }
        right++;
    }
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    if (goal == 0) return noOfSubarrays(nums, goal);
    return noOfSubarrays(nums, goal) - noOfSubarrays(nums, goal-1);
}

//TC - O(2N)
//SC - O(1)

//Another approach

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int sum = 0;
    int count = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for (int i=0; i<n; i++){
        sum += nums[i];
        int target = sum - goal;
        if (mpp.find(target) != mpp.end()){
            count = count + mpp[target];
        }
        mpp[sum]++;
    }
    return count;
}

//TC - O(N)
//SC - O(N)