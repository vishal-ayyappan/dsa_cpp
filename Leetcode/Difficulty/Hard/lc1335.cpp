#include <bits/stdc++.h>
using namespace std;

//Minimum Difficulty of a Job Schedule

//f(i, d) --> minimum difficulty of the job schedule from i, to n-1, with 'd' days remaining
int getMinDifficulty(vector<int>& jobDifficulty, int i, int d, vector<vector<int>>& dp){
    if (dp[i][d] != -1) return dp[i][d];
    //Base Case
    if (d == 1){
        //If this is the last day, get the max difficulty of that day.
        int maxi = 0;
        for (int k=i; k<jobDifficulty.size(); k++){
            maxi = max(maxi, jobDifficulty[k]);
        }
        return dp[i][d] = maxi;
    }
    int mini = INT_MAX;
    //Have a running maximum (for difficulty for that day)
    int diffMax = 0;
    //Every day should have atleast one task done
    for (int k=i; k<jobDifficulty.size()-d+1; k++){
        diffMax = max(diffMax, jobDifficulty[k]);
        //Go to the next day
        int nextDay = getMinDifficulty(jobDifficulty, k+1, d-1, dp) + diffMax;
        mini = min(mini, nextDay);
    }
    return dp[i][d] = mini;
}


int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) return -1;
    vector<vector<int>> dp (n+1, vector<int> (d+1, -1));
    getMinDifficulty(jobDifficulty, 0, d, dp); 
    return dp[0][d];
}


//DP --> Tabulation
int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) return -1;
    vector<vector<int>> dp (n+1, vector<int> (d+1, 0));
    //Base Case
    //Create a suffix max
    int maxi = INT_MIN;
    for (int i=n-1; i>=0; i--){
        maxi = max(maxi, jobDifficulty[i]);
        dp[i][1] = maxi;
    }
    //Body
    for (int i=n-2; i>=0; i--){
        for (int j=2; j<=d; j++){
            int mini = INT_MAX;
            int maxDifficultyCurr = 0;
            for (int k=i; k<n-j+1; k++){
                maxDifficultyCurr = max(jobDifficulty[k], maxDifficultyCurr);
                int nextDay = dp[k+1][j-1] + maxDifficultyCurr;
                mini = min(mini, nextDay);
            }
            dp[i][j] = mini;
        }
    }
    return dp[0][d];
}
