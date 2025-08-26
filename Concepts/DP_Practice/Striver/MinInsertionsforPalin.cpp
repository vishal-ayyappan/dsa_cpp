#include <bits/stdc++.h>
using namespace std;

// Form a palindrome

int getLCS(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + getLCS(s1, s2, i-1, j-1, dp);
    else dp[i][j] = max(getLCS(s1, s2, i-1, j, dp), getLCS(s1, s2, i, j-1, dp));
    return dp[i][j];
}

int findMinInsertions(string &s) {
    int n = s.length();
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;
    //Get Longest Common Subsequence
    vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
    int length = getLCS(s1, s2, n, n, dp);
    return n - length;
}