#include <bits/stdc++.h>
using namespace std;

//Have to do BackTracking
void getAllLIS(vector<int>& nums, vector<vector<int>>& parent, int i, vector<int>& ds, vector<vector<int>>& ans){
    ds.push_back(nums[i]);
    //If parent does not exist
    if (parent[i].size() == 0){
        reverse(ds.begin(), ds.end());
        ans.push_back(ds);
        reverse(ds.begin(), ds.end());
    }
    //If parent does exist
    else{
        for (int& new_i : parent[i]){
            getAllLIS(nums, parent, new_i, ds, ans);
        }
    }
    ds.pop_back();
}

vector<vector<int>> allLIS(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> parent (n);
    vector<int> dp (n, 1);
    int maxLen = 1;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (nums[i] > nums[j]){
                int length = 1 + dp[j];
                if (length > dp[i]){
                    parent[i].clear();
                    parent[i].push_back(j);
                }
                else if (length == dp[i]){
                    parent[i].push_back(j);
                }
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }
    //To get all the LIS
    vector<vector<int>> ans;
    for (int i=0; i<n; i++){
        if (dp[i] == maxLen){
            vector<int> ds;
            getAllLIS(nums, parent, i, ds, ans);
        }
    }
    return ans;
}