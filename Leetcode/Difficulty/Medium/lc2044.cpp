#include <bits/stdc++.h>
using namespace std;

//Count Number of Maximum Bitwise-OR Subsets

int getCount(vector<int>& nums, int idx, int target, int tempTarget){
    if (idx == nums.size()){
        if (tempTarget == target) return 1;
        return 0;
    }
    //Pick the element
    int pick = getCount(nums, idx+1, target, tempTarget | nums[idx]);
    //Not Pick the element
    int notPick = getCount(nums, idx+1, target, tempTarget);
    return pick + notPick;
}

int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();
    //Get the max bit wise OR value.
    int target = 0;
    for (int i=0; i<n; i++){
        target |= nums[i];
    }
    return getCount(nums, 0, target, 0);
}

//TC - O(2^N)
//SC - O(N)