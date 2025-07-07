#include <bits/stdc++.h>
using namespace std;

/*
0/ Placing an element at each index
*/
    
void getCombSum(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds, int idx){
    if (target == 0){
        ans.push_back(ds);
        return;
    }
    int n = candidates.size();
    if (idx == n || target < 0) return;
    //Placing an element at each index
    for (int i=idx; i<n; i++){
        if (i != idx && candidates[i] == candidates[i-1]) continue;
        ds.push_back(candidates[i]);
        getCombSum(candidates, target - candidates[i], ans, ds, idx+1);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    getCombSum(candidates, target, ans, ds, 0);
    return ans;
}