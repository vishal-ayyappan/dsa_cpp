#include <bits/stdc++.h>
using namespace std;

//Minimum insertions to make String Palindrome

int minInsertions(string s) {
    //Find the Longest palindromic subsequence and then, add the rest
    int n = s.length();
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;
    //Declare a DP array
    //dp[i][j] --> LCS of s1 (0 to i) and s2 (0 to j)
    vector<vector<int>> dp (n+1, vector<int> (n+1, 0));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int lcs = dp[n][n];
    int rest = n - lcs;
    return rest;
}