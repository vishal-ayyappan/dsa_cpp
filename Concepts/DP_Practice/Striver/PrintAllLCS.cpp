#include <bits/stdc++.h>
using namespace std;

//Print all LCS Sequences

// 0/ Generate the LCS count
// 1/ Do recusion/Backtracking ig

void getAllStrings(string& s1, string& s2, int length, string& ds, set<string>& ans, int i, int j, vector<vector<int>>& dp){
    if (length == 0){
        reverse(ds.begin(), ds.end());
        ans.insert(ds);
        reverse(ds.begin(), ds.end());
        return;
    }
    if (i == 0 || j == 0) return;
    if (s1[i-1] == s2[j-1]){
        ds.push_back(s1[i-1]);
        getAllStrings(s1, s2, length-1, ds, ans, i-1, j-1, dp);
        ds.pop_back();
    }
    else{
        if (dp[i-1][j] == dp[i][j]) getAllStrings(s1, s2, length, ds, ans, i-1, j, dp);
        if (dp[i][j-1] == dp[i][j]) getAllStrings(s1, s2, length, ds, ans, i, j-1, dp);
    }
}

vector<string> allLCS(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    //Find the LCS
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int length = dp[n][m];
    //Now get all the subsequence of length 'length'
    set<string> ans;
    string ds;
    vector<string> res;
    getAllStrings(s1, s2, length, ds, ans, n, m, dp);
    for (auto& it : ans) res.push_back(it);
    return res;
}