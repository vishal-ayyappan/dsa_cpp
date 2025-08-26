#include <bits/stdc++.h>
using namespace std;

//Merge Intervals

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();
    int i = 0;
    while (i < n){
        int start = arr[i][0];
        int end = arr[i][1];
        //For merging
        while (i+1 < n && arr[i+1][0] <= end){
            start = min(start, arr[i+1][0]);
            end = max(end, arr[i+1][1]);
            i++;
        }
        ans.push_back({start, end});
        i++;
    }
    return ans;
}