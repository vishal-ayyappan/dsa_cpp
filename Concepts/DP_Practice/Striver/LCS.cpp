#include <bits/stdc++.h>
using namespace std;

//Longest Common Subsequence

int getMaxLength(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
    //Base Case
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    //Do all the stuff
    //If the character is same
    if (s1[i] == s2[j]) dp[i][j] = 1 + getMaxLength(s1, s2, i-1, j-1, dp);
    else {
        int val1 = getMaxLength(s1, s2, i-1, j, dp);
        int val2 = getMaxLength(s1, s2, i, j-1, dp);
        dp[i][j] = max(val1, val2);
    }
    return dp[i][j];
}

int lcs(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    // dp[i][j] --> LCS of s1 0 to i and s2 0 to j.
    getMaxLength(s1, s2, n-1, m-1, dp);
    return dp[n-1][m-1];
}

//DP --> Tabulation
int lcs(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    // dp[i][j] --> LCS of s1 0 to i and s2 0 to j.
    //Base Case
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (s1[i] == s2[j]) {
                dp[i][j] = 1;
                if (i > 0 && j > 0) dp[i][j] += dp[i-1][j-1];
            }
            else {
                int val1 = 0;
                int val2 = 0;
                if (i > 0) val1 = dp[i-1][j];
                if (j > 0) val2 = dp[i][j-1];
                dp[i][j] = max(val1, val2);
            }
        }
    }
    return dp[n-1][m-1];
}
