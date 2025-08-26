#include <bits/stdc++.h>
using namespace std;

//Ninjas Training
int getMaxScore(vector<vector<int>> &points, vector<vector<int>>& dp, int day, int past_activity){
    if (day < 0) return 0;
    if (dp[day][past_activity] != -1) return dp[day][past_activity];
    //Do all the activities
    int maxi = 0;
    for (int i=0; i<3; i++){
        if (past_activity == i) continue;
        //Do that activity and go to the next day
        int value = points[day][i] + getMaxScore(points, dp, day-1, i);
        maxi = max(maxi, value);
    }
    dp[day][past_activity] = maxi;
    return dp[day][past_activity];
}

int ninjaTraining(int n, vector<vector<int>> &points){
    //Each day, he can do either one of 3 but not the past days activity
    vector<vector<int>> dp (n, vector<int> (3, -1));
    //dp[i][j] --> max score you can get from 0 to i, given last activity is j
    int maxi = INT_MIN;
    for (int i=0; i<3; i++){
        int value = points[n-1][i] + getMaxScore(points, dp, n-2, i);
        maxi = max(maxi, value);
    }
    return maxi;
}

//DP --> Tabulation
int ninjaTraining(int n, vector<vector<int>> &points){
    //Each day, he can do either one of 3 but not the past days activity
    vector<vector<int>> dp (n, vector<int> (3, -1));
    //dp[i][j] --> max score you can get from 0 to i, given last activity is j
    //Write the base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    for (int day=1; day<n; day++){
        for (int activity=0; activity<3; activity++){
            int maxi = 0;
            for (int i=0; i<3; i++){
                if (i == activity) continue;
                int value = points[day][i] + dp[day-1][i];
                maxi = max(maxi, value);
            }
            dp[day][activity] = maxi;
        }
    }
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}
