#include <bits/stdc++.h>
using namespace std;


// Put the pivot at the right postiton
// Call for the left side and the right side (Recursive)

void quicksort(vector<int>& nums, int start, int end){
    if (start >= end) return;
    int pivot = nums[start];
    int pivotIdx = start;
    int i = start;
    int j = end;
    while (i <= j){
        while (i <= j && nums[i] <= pivot) i++;
        while (i <= j && nums[j] > pivot) j--;
        if (i<j) swap(nums[i], nums[j]);
    }
    swap(nums[pivotIdx], nums[j]);
    quicksort(nums, start, j-1);
    quicksort(nums, j+1, end);
}

vector<int> sortArray(vector<int>& nums) {
    quicksort(nums, 0, nums.size()-1);
    return nums;
}

//TC - O(NlogN),  Worst case -> O(N*N) (already in sorted order)
//SC - O(N) (Worst case), O(logN) (average case)