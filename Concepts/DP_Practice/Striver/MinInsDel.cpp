#include <bits/stdc++.h>
using namespace std;

// Minimum number of deletions and insertions
int getMinOperations(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
    // If s1 is over
    if (i == 0) return dp[i][j] = j; //Inserting j elements
    // If s2 is over
    if (j == 0) return dp[i][j] = i; //Deleting i elements
    if (dp[i][j] != -1) return dp[i][j];
    // Do all the stuff
    if (s1[i-1] == s2[j-1]) dp[i][j] = getMinOperations(s1, s2, i-1, j-1, dp);
    else{
        int insert = 1 + getMinOperations(s1, s2, i, j-1, dp);
        int del = 1 + getMinOperations(s1, s2, i-1, j, dp);
        dp[i][j] = min(insert, del);
    }
    return dp[i][j];
}

int minOperations(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    // dp[i][j] --> min no of operations needed to make s1 (0 to i-1) to s2 (0 to j-1)
    getMinOperations(s1, s2, n, m, dp);
    return dp[n][m];
}

//DP --> Tabulation
int minOperations(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    // dp[i][j] --> min no of operations needed to make s1 (0 to i-1) to s2 (0 to j-1)
    //Base Case
    for (int i=0; i<=n; i++) dp[i][0] = i;
    for (int j=0; j<=m; j++) dp[0][j] = j;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
        }
    }
    return dp[n][m];
}
