#include <bits/stdc++.h>
using namespace std;

//Divide and conquer
// Go to the depths and sort it from the depths

void merge(vector<int>& nums, int start, int middle, int end){
    vector<int> v;
    int i = start;
    int j = middle+1;
    while (i <= middle && j <= end){
        if (nums[i] <= nums[j]){
            v.push_back(nums[i]);
            i++;
        }
        else{
            v.push_back(nums[j]);
            j++;
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

void mergesort(vector<int>& nums, int start, int end){
    if (start >= end) return;
    int middle = start + (end-start)/2;
    mergesort(nums, start, middle);
    mergesort(nums, middle+1, end);
    merge(nums, start, middle, end);
}

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    mergesort(nums, 0, n-1);
    return nums;
}

//TC - O(NlogN)
//SC - O(N) + [O(logN)-> Recursive stack space]