#include<bits/stdc++.h>
using namespace std;

//Subarrays with K Different Integers

/*
Approach : Subarray with at most k diff integers - Subarray with at most k-1 diff integers
*/

int subArrays(vector<int>& nums, int k){
    if (k == 0) return 0;
    int n = nums.size();
    int left = 0;
    int right = 0;
    int count = 0;
    //To store the frequency
    unordered_map<int, int> mpp;
    while (right < n){
        mpp[nums[right]]++;
        while (mpp.size() > k){
            mpp[nums[left]]--;
            if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
            left++;
        }
        if (mpp.size() <= k){
            count += right - left + 1;
        }
        right++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subArrays(nums, k) - subArrays(nums, k-1);
}

//TC - O(2N)
//SC - O(1)