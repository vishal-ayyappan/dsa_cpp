#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int i = 0;
    while (i < n){
        int start = intervals[i][0];
        int end = intervals[i][1];
        //If there is overlap
        while (i < n-1 && end >= intervals[i+1][0]){
            //Check the minimum val
            if (intervals[i+1][0] < start){
                start = intervals[i+1][0];
            }
            //Check the maximum val
            if (intervals[i+1][1] > end){
                end = intervals[i+1][1];
            }
            i++;
        }
        ans.push_back({start, end});
        i++;
    }
    return ans;
}