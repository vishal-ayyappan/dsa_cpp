#include <bits/stdc++.h>
using namespace std;

//Insertion sort with gaps
// Shell sort with gap 1 is insertion sort.
// So similarly do insertion sort with the gap (starting from n/2 and then iteratively reduce by /2)

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    int gap = n/2;
    while (gap > 0){
        for (int i=gap; i<n; i++){
            int j = i-gap;
            while (j>=0 && nums[j] > nums[j+gap]){
                swap(nums[j+gap], nums[j]);
                j -= gap;
            }
        }
        gap = gap/2;
    }
    return nums;
}

//TC Worst Case O(N*N)
//SC O(1)