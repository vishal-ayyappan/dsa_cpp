#include <bits/stdc++.h>
using namespace std;

/*
Do a standard binary search (Implement lower bound)
*/

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right){
        int middle = left + (right-left)/2;
        if (nums[middle] >= target) right = middle - 1;
        else left = middle + 1;
    }
    return left;
}

//TC - O(logN)
//SC - O(1)