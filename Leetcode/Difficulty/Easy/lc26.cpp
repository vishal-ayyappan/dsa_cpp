#include <bits/stdc++.h>
using namespace std;

//Remove Duplicates from Sorted Array

/*
As it is sorted, do a simple traversal
*/

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int k = 1;
    int val = nums[0];
    int idx = 1;
    for (int i=1; i<n; i++){
        if (val == nums[i]) continue;
        else{
            val = nums[i];
            nums[idx] = val;
            idx++;
            k++;
        }
    }
    return k;
}

//TC - O(N)
//SC - O(1)