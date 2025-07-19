#include <bits/stdc++.h>
using namespace std;

//Delete Operation for Two Strings
//Get the Longest Common Subsequence and then delete the rest

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    //Declare the DP array
    // dp[i][j] --> LCS of word1 (0 to i-1) and word2 (0 to j-1)
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int lcs = dp[n][m];
    int removal1 = n - lcs;
    int removal2 = m - lcs;
    return removal1 + removal2;
}