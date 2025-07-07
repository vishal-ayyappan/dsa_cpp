#include <bits/stdc++.h>
using namespace std;

/*
0/ Place an element at each index
*/

void getPermutations(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, 
    vector<bool>& visited ,int idx){
    if (idx == nums.size()){
        ans.push_back(ds);
        return;
    }
    for (int i=0; i<nums.size(); i++){
        if (!visited[i]){
            ds.push_back(nums[i]);
            visited[i] = true;
            getPermutations(nums, ans, ds, visited, idx+1);
            ds.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> visited (n, false);
    getPermutations(nums, ans, ds, visited, 0);
    return ans;
}