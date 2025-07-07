//Sliding Window Maximum

#include<bits/stdc++.h>
using namespace std;

// 1/ Decreasing monotonic queue (Storing value and index)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<pair<int,int>> q;
    for (int i=0; i<nums.size(); i++){
        if (q.empty()) q.push_back({nums[i], i});
        while (!q.empty() && nums[i] > q.back().first){
            q.pop_back();
        }
        q.push_back({nums[i], i});
        if (i >= k-1){
            while (i - q.front().second >= k){
                q.pop_front();
            }
            ans.push_back(q.front().first);
        }
    }
    return ans;
}

// TC - O(N) On average
// SC - O(2N) 