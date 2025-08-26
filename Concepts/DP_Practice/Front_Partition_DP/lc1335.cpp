#include <bits/stdc++.h>
using namespace std;

//Minimum Difficulty of a Job Schedule
int getMinDifficulty(vector<int>& jobDifficulty, int start, int days, vector<vector<int>>& dp){
    //Base Case
    if (days == 1){
        //Max job difficulty of the remaining days
        int maxi = INT_MIN;
        for (int i=start; i<jobDifficulty.size(); i++){
            maxi = max(maxi, jobDifficulty[i]);
        }
        dp[start][days] = maxi;
        return dp[start][days];
    }
    if (dp[start][days] != -1) return dp[start][days];
    //Keep a curr max
    int diff_at_that_day = INT_MIN;
    int curr_diff = INT_MAX;
    for (int i=start; i<=jobDifficulty.size()-days; i++){
        diff_at_that_day = max(diff_at_that_day, jobDifficulty[i]);
        //You either go to the next day, or continue the job at that day
        int difficulty = diff_at_that_day + getMinDifficulty(jobDifficulty, i+1, days-1, dp);
        curr_diff = min(curr_diff, difficulty);
    }
    dp[start][days] = curr_diff;
    return dp[start][days];
}

int minDifficulty(vector<int>& jobDifficulty, int d) {
    //There should be atleast one task per day
    // dp[i][j] --> min difficulty of the job, where you still have to complete i to n-1, in d days
    int n = jobDifficulty.size();
    if (d > n) return -1;
    vector<vector<int>> dp (n, vector<int> (d+1, -1));
    getMinDifficulty(jobDifficulty, 0, d, dp);
    return dp[0][d];
}