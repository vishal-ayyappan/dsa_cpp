#include <bits/stdc++.h>
using namespace std;

//Reverse Pairs

void merge(vector<int>& nums, int start, int middle, int end){
    int i = start;
    int j = middle+1;
    int count = 0;
    vector<int> v;
    while (i <= middle && j <= end){
        if (nums[i] >= nums[j]){
            v.push_back(nums[j]);
            j++;
        }
        else{
            v.push_back(nums[i]);
            i++;
        }
    }
    while (i <= middle){
        v.push_back(nums[i]);
        i++;
    }
    while (j <= end){
        v.push_back(nums[j]);
        j++;
    }
    int idx = 0;
    for (int i=start; i<=end; i++){
        nums[i] = v[idx];
        idx++;
    }
}

int getRevPairs(vector<int>& nums, int start, int middle, int end){
    int i = start;
    int j = middle+1;
    int count = 0;
    while (i <= middle){
        while (j <= end && 1LL*nums[j]*2 < 1LL*nums[i]){
            j++;
        }
        count += j - (middle + 1);
        i++;
    }
    return count;
}

int getCount(vector<int>& nums, int start, int end){
    if (start >= end) return 0;
    int middle = start + (end-start)/2;
    //Divide and conquer
    int left = getCount(nums, start, middle);
    int right = getCount(nums, middle+1, end);
    int value = getRevPairs(nums, start, middle, end);
    merge(nums, start, middle, end);
    return left + right + value;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    return getCount(nums, 0,  n-1);
}