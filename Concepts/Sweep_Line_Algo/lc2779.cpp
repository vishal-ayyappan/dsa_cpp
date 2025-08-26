#include <bits/stdc++.h>
using namespace std;

//Maximum Beauty of an Array After Applying Operation

//Easy Intuition : Get the ranges and apply the line sweep algo of the ranges. (Get the max intersection point)

int maximumBeauty(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> mpp;
    for (int i=0; i<n; i++){
        int from = nums[i] - k;
        int to = nums[i] + k;
        mpp[from]++;
        mpp[to+1]--;
    }
    int sum = 0;
    int maxi = 0;
    for (auto& it : mpp){
        sum += it.second;
        maxi = max(maxi, sum);
    }
    return maxi;
}

//Approach 2 (Using Max Overlap interval logic) --> Similar to that of line sweep

int maximumBeauty(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> intervals (n, vector<int> (2, 0));
    for (int i=0; i<n; i++){
        intervals[i][0] = nums[i]-k;
        intervals[i][1] = nums[i]+k;
    }
    //Now sort the intervals
    sort(intervals.begin(), intervals.end());
    //Put it in the queue (to check overlapping)
    //Monotonic Queue.
    queue<int> q;
    int maxi = 0;
    for (int i=0; i<n; i++){
        while (!q.empty() && intervals[i][0] > q.front()) q.pop();
        q.push(intervals[i][1]);
        int size = q.size();
        maxi = max(maxi, size);
    }
    return maxi;
}


//Approach 3 (Using binary Search) (A bit untuitive)

int maximumBeauty(vector<int>& nums, int k) {
    //Two elements (x, y) can have the same value if x+k >= y-k of y <= x + 2*k
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int maxi = 0;
    for (int i=0; i<n; i++){
        int target = nums[i] + 2*k;
        //Get the upper bound
        int idx = upper_bound(nums.begin() + i, nums.end(), target) - nums.begin();
        int size = 0;
        if (idx != n && nums[idx] == target) size = idx - i + 1;
        else size = idx - i;
        maxi = max(maxi, size);
    }
    return maxi;
}
