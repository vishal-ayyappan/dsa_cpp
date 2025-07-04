#include <bits/stdc++.h>
using namespace std;

/*
0/ Place an element at each index
*/

void getPermutations(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, 
    unordered_map<int,bool>& mpp ,int idx){
    if (idx == nums.size()){
        ans.push_back(ds);
        return;
    }
    for (int i=0; i<nums.size(); i++){
        if (mpp.find(nums[i]) == mpp.end()){
            ds.push_back(nums[i]);
            mpp[nums[i]] = true;
            getPermutations(nums, ans, ds, mpp, idx+1);
            ds.pop_back();
            mpp.erase(nums[i]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    unordered_map<int, bool> mpp;
    getPermutations(nums, ans, ds, mpp, 0);
    return ans;
}