#include <bits/stdc++.h>   
using namespace std;

// Regular Expression Matching (DP, A modification of Knapsack)

int getMatch(string& s, string& p, int i, int j, vector<vector<int>>& dp){
    if (i == s.length()) {
        for (int idx = j; idx < p.length(); idx++){
            if (idx+1 < p.length() && p[idx+1] == '*') idx++;
            else return 0;
        }
        return 1;
    }
    if (j == p.length()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    //Check if the next character is *
    if (j + 1 < p.length() && p[j+1] == '*'){
        //You either pick this char or you do not
        int notPick = getMatch(s, p, i, j+2, dp);
        int pick = 0;
        if (s[i] == p[j] || p[j] == '.') pick = getMatch(s, p, i+1, j, dp);
        dp[i][j] = pick + notPick;
    }
    //If the next char is not '*'
    else {
        int pick = 0;
        if (s[i] == p[j] || p[j] == '.') pick = getMatch(s, p, i+1, j+1, dp);
        dp[i][j] = pick;
    }
    return dp[i][j];
}

bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<vector<int>> dp (m+1, vector<int> (n+1, -1));
    // dp[i][j] --> check whether i to m-1 matches j to n-1
    getMatch(s, p, 0, 0, dp);
    return dp[0][0];
}