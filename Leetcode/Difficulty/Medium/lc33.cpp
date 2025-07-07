#include <bits/stdc++.h>
using namespace std;

//Search in rotated sorted array

/*
Get the index where it is rotated
*/

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    //Get the idx where it is rotated
    while (left <= right){
        int middle = left + (right-left)/2;
        if (nums[middle] == target) return middle;
        //If left sorted
        if (nums[left] <= nums[middle]){
            if (nums[left] <= target && nums[middle] > target){
                right = middle - 1;
            }
            else left = middle + 1;
        }
        //If right sorted
        else if (nums[right] >= nums[middle]){
            if (nums[middle] < target && nums[right] >= target){
                left = middle + 1;
            }
            else right = middle - 1;
        }
    }
    return -1;
}