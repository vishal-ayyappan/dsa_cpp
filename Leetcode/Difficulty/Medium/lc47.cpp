#include <bits/stdc++.h>
using namespace std;

//Permutations II (Get unique combinations)
void getPermutations(vector<int>& nums, vector<bool>& visited, vector<int>& ds, vector<vector<int>>& ans){
    //Base Case
    if (ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    //Logic
    for (int i=0; i<nums.size(); i++){
        if (visited[i]) continue;
        //Skip Duplicates only if previous duplicate is not used
        if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
        ds.push_back(nums[i]);
        visited[i] = true;
        getPermutations(nums, visited, ds, ans);
        ds.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<int> ds;
    vector<bool> visited (n, false);
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    getPermutations(nums, visited, ds, ans);
    return ans;
}

//Swap Logic
void getPermutationsII(vector<int>& nums, vector<vector<int>>& ans, int idx){
    if (idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    //Each element is used only once per recursive level
    unordered_set<int> st;
    for (int i=idx; i<nums.size(); i++){
        if (st.count(nums[i])) continue;
        st.insert(nums[i]);
        swap(nums[i], nums[idx]);
        getPermutationsII(nums, ans, idx+1);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    getPermutationsII(nums, ans, 0);
    return ans;
}

