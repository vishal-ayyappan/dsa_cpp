#include <bits/stdc++.h>
using namespace std;

/*
0/ Traverse from the back, stop where the next element is lesser than the current element
1/ Find the min value greater than that element and swap it
2/ Sort the rest right to that index
*/

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx = -1;
    for (int i=n-1; i>0; i--){
        if (nums[i] > nums[i-1]){
            idx = i-1;
            break;
        }
    }
    if (idx == -1){
        sort(nums.begin(), nums.end());
        return;
    }
    int value = nums[idx];
    int minVal = nums[idx+1];
    int swapIdx = idx+1;
    for (int i=idx+2; i<n; i++){
        if (nums[i] > value){
            minVal = min(minVal, nums[i]);
            if (minVal == nums[i]) swapIdx = i;
        }
    }
    swap(nums[idx], nums[swapIdx]);
    sort(nums.begin()+idx+1, nums.end());
}

//TC - O(N) + O(NlogN)
//SC - O(1)