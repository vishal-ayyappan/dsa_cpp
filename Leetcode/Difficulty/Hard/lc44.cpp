#include <bits/stdc++.h>
using namespace std;

//WildCard Matching Pattern

//DP --> Memoization
int getMatch(string& s, string& p, int idx1, int idx2, vector<vector<int>>& dp){
    //Base Cases
    if (idx1 == 0 && idx2 == 0) {
        dp[idx1][idx2] = 1;
        return dp[idx1][idx2];
    }
    //String 1 is exhausted, to be true, the rest of string 1 should be "*"
    if (idx1 == 0){
        dp[idx1][idx2] = 1;
        for (int i=idx2; i>=1; i--){
            if (p[i-1] != '*') {
                dp[idx1][idx2] = 0;
                break;
            }
        }
        return dp[idx1][idx2];
    }
    if (idx2 == 0) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2]; 
    //If character matches
    if (s[idx1-1] == p[idx2-1]){
        dp[idx1][idx2] = getMatch(s, p, idx1-1, idx2-1, dp);
    }
    else if (p[idx2-1] == '?'){
        dp[idx1][idx2] = getMatch(s, p, idx1-1, idx2-1, dp);
    }
    else if (p[idx2-1] == '*'){
        int matchZero = getMatch(s, p, idx1, idx2-1, dp);
        int matchMorethanZero = getMatch(s, p, idx1-1, idx2, dp);
        dp[idx1][idx2] = matchZero || matchMorethanZero;
    }
    else dp[idx1][idx2] = 0;
    return dp[idx1][idx2]; 
}

bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();
    //Declare a DP array
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    getMatch(s, p, n, m, dp);
    if (dp[n][m] == 1) return true;
    return false;
}