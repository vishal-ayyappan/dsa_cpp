#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string &s1, string &s2) {
    //Find the longest common subsequence
    //Fill the table
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    //dp[i][j] --> LCS of s1 (0 to i-1) and s2 (0 to j-1)
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            //if the character matches
            if (s1[i-1] == s2[i-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    //Now backtrack to get the shortest sequence
    int i = n;
    int j = m;
    string res;
    while (i >= 0 && j >= 0){
        if (i == 0 && j == 0){
            i--;
            j--;
            continue;
        }
        if (i == 0 && j != 0){
            res.push_back(s2[j-1]);
            j--;
            continue;
        }
        if (j == 0 && i != 0){
            res.push_back(s1[i-1]);
            i--;
            continue;
        }
        if (s1[i-1] == s2[j-1]) {
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if (dp[i-1][j] > dp[i][j-1]){
                res.push_back(s1[i-1]);
                i--;
            }
            else{
                res.push_back(s2[j-1]);
                j--;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res.size();
}