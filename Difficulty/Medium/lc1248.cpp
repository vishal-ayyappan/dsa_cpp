#include <bits/stdc++.h>
using namespace std;

//Count number of nice subarrays (k odd elements)

//At most k odd - At most (k-1) odd

int subArrays(vector<int>& nums, int k){
    int n = nums.size();
    int left = 0;
    int right = 0;
    int count = 0;
    int oddCount = 0;
    while (right < n){
        if (nums[right]&1) oddCount++;
        while (oddCount > k){
            if (nums[left]&1) oddCount--;
            left++;
        }
        if (oddCount <= k){
            count += right - left + 1;
        }
        right++;
    }
    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return subArrays(nums, k) - subArrays(nums, k-1);
}

//TC - O(2N)
//SC - O(1)