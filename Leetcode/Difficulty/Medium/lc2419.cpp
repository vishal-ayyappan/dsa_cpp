#include <bits/stdc++.h>
using namespace std;

//Longest Subarray With Maximum Bitwise AND

// AND operation of 2 elements will be <= the elements (Always)
// We need the longest, So, we have to figure out the length of the largest subarray of the max element

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int maxEl = *max_element(nums.begin(), nums.end());
    int maxCount = 0;
    int i = 0;
    while (i < n){
        int count = 0;
        if (nums[i] == maxEl){
            while (i<n && nums[i] == maxEl){
                count++;
                i++;
            }
            maxEl = max(maxEl, count);
        }
        else i++;
    }
    return maxCount;
}