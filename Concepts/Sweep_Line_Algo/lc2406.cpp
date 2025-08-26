#include <bits/stdc++.h>
using namespace std;

//Divide Intervals Into Minimum Number of Groups

//Intuition --> Max no of intervals having an overlap (coz, you would have to put those in different groups)

int minGroups(vector<vector<int>>& intervals) {
    //We can do sweep lines logic, whenever the sum count goes to max increase the count
    map<int, int> mpp;
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    for (int i=0; i<n; i++){
        int from = intervals[i][0];
        int to = intervals[i][1];
        mpp[from]++;
        mpp[to+1]--;
    }
    int sum = 0;
    int maxSum = 0;
    for (auto& it : mpp){
        sum += it.second;
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}