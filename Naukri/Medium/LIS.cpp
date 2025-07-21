#include <bits/stdc++.h> 
using namespace std;

//DP and constructive algo approach is done in leetcode section


//This is using binary search
int LIS(vector<int> &heights, int n){	
	vector<int> ans;
    ans.push_back(heights[0]);
    for (int i=1; i<n; i++){
        //Get the index
        int idx = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
        if (idx == ans.size()) ans.push_back(heights[i]);
        else ans[idx] = heights[i];
    }	
    return ans.size();
}

//TC - O(NlogN)