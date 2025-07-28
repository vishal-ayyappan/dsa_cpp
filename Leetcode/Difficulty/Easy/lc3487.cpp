#include <bits/stdc++.h>
using namespace std;

//Maximum Unique Subarray Sum After Deletion

int maxSum(vector<int>& nums) {
    unordered_set<int> st;
    int res = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] > 0) st.insert(nums[i]);
    }
    if (st.empty()) {
        res = *max_element(nums.begin(), nums.end());
    }
    for (auto& it : st){
        res += it;
    }
    return res;
}

//TC - O(N)
//SC - O(N)