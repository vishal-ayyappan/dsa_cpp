#include <bits/stdc++.h>
using namespace std;

/*
lower bound and upper bound concept
*/

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (first == last) return {-1,-1};
    return {first, last};
}

//TC - O(logN)
//SC - O(1)

//Implementing upper and lower bound

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n-1;
    while (left <= right){
        int middle = left + (right-left)/2;
        //lower bound
        if (nums[middle] >= target) right = middle - 1;
        else if (nums[middle] < target) left = middle + 1;
    }
    int first = left;
    int left1 = 0;
    int right1 = n-1;
    while (left1 <= right1){
        int middle1 = left1 + (right1-left1)/2;
        //Upper bound
        if (nums[middle1] > target) right1 = middle1 - 1;
        else if (nums[middle1] <= target) left1 = middle1 + 1;
    }
    int second = left1;
    if (first == second) return {-1,-1};
    return {first, second-1};
}

//TC - O(logN)
//SC - O(1)
