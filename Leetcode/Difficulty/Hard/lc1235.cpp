#include <bits/stdc++.h>
using namespace std;

//Maximum Profit in Job Scheduling

int getNextJobIdx(vector<vector<int>>& logs, int start, int target){
    int l = start;
    int r = logs.size()-1;
    while (l <= r){
        int m = l + (r-l)/2;
        //Check the start times
        if (logs[m][0] < target) l = m+1;
        else r = m-1;
    }
    return l;
}

int getMax(vector<vector<int>>& logs, int i, vector<int>& dp){
    //Base Case
    if (i == logs.size()) return 0;
    if (dp[i] != -1) return dp[i];
    //do the recursion calls
    int notPick = getMax(logs, i+1, dp);
    int nextJobIdx = getNextJobIdx(logs, i+1, logs[i][1]);
    int pick = logs[i][2] + getMax(logs, nextJobIdx, dp);
    return dp[i] = max(pick, notPick);
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = profit.size();
    vector<vector<int>> logs (n, vector<int> (3));
    for (int i=0; i<n; i++){
        logs[i][0] = startTime[i];
        logs[i][1] = endTime[i];
        logs[i][2] = profit[i];
    }
    sort(logs.begin(), logs.end());
    int maxEndTime = *max_element(endTime.begin(), endTime.end());
    vector<int> dp (n, -1);
    //Max Profit you can get from i to n-1, given endtime is j
    getMax(logs, 0, dp);
    return dp[0];
}


