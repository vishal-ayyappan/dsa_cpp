#include <bits/stdc++.h>
using namespace std;

/*
Store the element and the indexes in the hashmap while iterating 
*/

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mpp;
    for (int i=0; i<n; i++){
        //If the element is already present
        int val = target - nums[i];
        if (mpp.find(val) != mpp.end()){
            int first = mpp[val];
            int second = i;
            return {first, second};
        }
        mpp[nums[i]] = i;
    }
    return {-1,-1};
}

//TC - O(N)
//SC - O(N)