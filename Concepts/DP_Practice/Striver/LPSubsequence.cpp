#include <bits/stdc++.h>
using namespace std;

//Longest Palindromic Subsequence
int getLPS(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
    //Base Case
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + getLPS(s1, s2, i-1, j-1, dp);
    else dp[i][j] = max(getLPS(s1, s2, i-1, j, dp), getLPS(s1, s2, i, j-1, dp));
    return dp[i][j];
}

int longestPalinSubseq(string &s) {
    int n = s.length();
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;
    vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
    // dp[i][j] --> lcs of s1 (0 to i-1) and s2 (0 to j-1)
    getLPS(s1, s2, n, n, dp);
    return dp[n][n];
}