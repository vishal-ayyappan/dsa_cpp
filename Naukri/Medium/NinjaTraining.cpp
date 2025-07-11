#include <bits/stdc++.h>
using namespace std;

//Recursion
//1/ Write the recurrence relation, in terms of indexes
//2/ Do all the stuffs based on it
//3/ Return what the question asks you

int getMaxScore(vector<vector<int>>& points, int day, int task){
    //Base Cases
    if (day < 0) return 0;
    int maxi = INT_MIN;
    for (int i=points[0].size()-1; i>=0; i--){
        if (task != i){
            int val = points[day][i] + getMaxScore(points, day-1, i);
            maxi = max(maxi, val);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    int tasks = points[0].size();
    //Initially you have not performed any tasks
    //Index --> Cuurent Day, Last Days' Task
    return getMaxScore(points, n-1, tasks);
}

//For the above solution, you get TLE

//DP with memoization
//Have a DP matrix, that you update if it is not -1. This question will have overlapping sub intervals

int getMaximumScore(vector<vector<int>>& points, int day, int prevTask, vector<vector<int>>& dp){
    if (day < 0) return 0;
    if (dp[day][prevTask] != -1) return dp[day][prevTask];
    int maxi = INT_MIN;
    for (int i=points[0].size()-1; i>=0; i--){
        if (prevTask != i){
            int value = points[day][i] + getMaximumScore(points, day-1, i, dp);
            maxi = max(value, maxi);
        }
    }
    dp[day][prevTask] = maxi;
    return dp[day][prevTask]; 
}

int ninjaTraining(int n, vector<vector<int>> &points){
    int tasks = points[0].size();
    //Initializing the DP array
    // tasks + 1, because we wanna a separate column, for "no prev tasks done"
    vector<vector<int>> dp (n, vector<int> (tasks+1, -1));
    //Initially you have not performed any tasks
    //Index --> Cuurent Day, Last Days' Task
    getMaximumScore(points, n-1, tasks, dp);
    return dp[n-1][tasks];
}

//TC - O(M*N)
//SC - O(2*M*N)

//DP --> Tabulation
int ninjaTraining(int n, vector<vector<int>> &points){
    int m = points[0].size();
    //Initializing the DP array
    vector<vector<int>> dp (n, vector<int> (m+1, -1));
    //dp[i][j] represents max points till day i, where prev task is j
    //Base Cases
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][2], points[0][0]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max({points[0][1], points[0][2], points[0][0]});
    for (int day=1; day<n; day++){
        for (int last=0; last<=m; last++){
            int maxi = 0;
            for (int task = 0; task < m; task++){
                if (last != task){
                    int value = points[day][task] + dp[day-1][task];
                    maxi = max(maxi, value);
                }
            }
            dp[day][last] = maxi;
        }
    }
    int ans = *max_element(dp[n-1].begin(), dp[n-1].end());
    return ans;
}


//Space Optimization (You only need an array)
int ninjaTraining(int n, vector<vector<int>> &points){
    int m = points[0].size();
    //Initializing the DP array
    vector<int> dp (m+1);
    //dp[i][j] represents max points till day i, where prev task is j
    //Base Cases
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][2], points[0][0]);
    dp[2] = max(points[0][1], points[0][0]);
    dp[3] = max({points[0][1], points[0][2], points[0][0]});
    for (int day=1; day<n; day++){
        vector<int> temp (m+1);
        for (int last=0; last<=m; last++){
            int maxi = 0;
            for (int task = 0; task < m; task++){
                if (last != task){
                    int value = points[day][task] + dp[task];
                    maxi = max(maxi, value);
                }
            }
            temp[last] = maxi;
        }
        dp = temp;
    }
    int ans = *max_element(dp.begin(), dp.end());
    return ans;
}

