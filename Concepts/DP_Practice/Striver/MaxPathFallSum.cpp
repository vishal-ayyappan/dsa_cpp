#include <bits/stdc++.h>
using namespace std;

//Maximum Path Falling Sum

int getMaxSum(vector<vector<int>>& mat, vector<vector<int>>& dp, int row, int col){
    //Base Case
    if (row == 0) return dp[row][col] = mat[row][col];
    if (dp[row][col] != -1) return dp[row][col];
    //Do the recurrence relation
    //Can go in three ways
    //Go diag left
    int left = 0;
    if (col > 0) left = getMaxSum(mat, dp, row-1, col-1);
    //Go up
    int middle = getMaxSum(mat, dp, row-1, col);
    //Go Diag Right
    int right = 0;
    if (col < mat[0].size()-1) right = getMaxSum(mat, dp, row-1, col+1);
    dp[row][col] = mat[row][col] + max({left, right, middle});
    return dp[row][col];
}

int maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    //dp[i][j] --> max Sum you can get from 0 to i, given you should pick j now
    int maxi = INT_MIN;
    for (int i=0; i<m; i++){
        int value = getMaxSum(mat, dp, n-1, i);
        maxi = max(maxi, value);
    }
    return maxi;
}

//DP --> Tabulation
int maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    //dp[i][j] --> max Sum you can get from 0 to i, given you should pick j now
    //Write the Base Cases
    for (int i=0; i<m; i++) dp[0][i] = mat[0][i];
    //Do what you did in recursion
    for (int day=1; day<n; day++){
        for (int activity=0; activity<m; activity++){
            //You can go three ways
            int diagLeft = 0;
            if (activity > 0) diagLeft = dp[day-1][activity-1];
            int up = dp[day-1][activity];
            int diagRight = 0;
            if (activity < m-1) diagRight = dp[day-1][activity+1];
            dp[day][activity] = mat[day][activity] + max({diagLeft, up, diagRight});
        }
    }
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}
