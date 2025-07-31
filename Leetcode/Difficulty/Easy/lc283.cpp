#include <bits/stdc++.h>
using namespace std;

//Move Zeroes

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = -1;
    for (int i=0; i<n; i++){
        if (nums[i] == 0){
            j = i;
            break;
        }
    }
    //If there are no zeros.
    if (j == -1) return;
    int i = 0;
    while (i < n){
        if (i >= j){
            if (nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        i++;
    }
}