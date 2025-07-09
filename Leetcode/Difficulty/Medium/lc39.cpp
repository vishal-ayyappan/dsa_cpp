#include <bits/stdc++.h>
using namespace std;

/*
//Use the inclusion exclusion principle
*/

void getCombSum(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds, int idx){
    //Base case
    if (target < 0 || idx == candidates.size()) return;
    if (target == 0){
        ans.push_back(ds);
        return;
    }
    ds.push_back(candidates[idx]);
    getCombSum(candidates, target - candidates[idx], ans, ds, idx);
    ds.pop_back();
    getCombSum(candidates, target, ans, ds, idx+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    getCombSum(candidates, target, ans, ds, 0);
    return ans;
}