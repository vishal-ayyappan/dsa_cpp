#include <bits/stdc++.h>
using namespace std;

//Wildcard Pattern Matching
int checkIfMatches(string& txt, string& pat, int i, int j, vector<vector<int>>& dp){
    //Base Case
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 && j == 0) return dp[i][j] = 1;
    if (j == 0) return dp[i][j] = 0;
    if (i == 0) {
        //All the elements from 0 to j must be '*'
        while (j > 0){
            if (pat[j-1] != '*') return dp[i][j] = 0;
            j--;
        }
        return dp[i][j] = 1;
    }
    //Check all the case
    //if pat's char matcehs the txt's char
    if (txt[i-1] == pat[j-1] || pat[j-1] == '?'){
        if (checkIfMatches(txt, pat, i-1, j-1, dp) == true) return dp[i][j] = 1;
    }
    //If pat's char is '*'
    else if (pat[j-1] == '*'){
        //It can either be part of the subsequence or no
        if (checkIfMatches(txt, pat, i-1, j, dp) || checkIfMatches(txt, pat, i, j-1, dp)) return dp[i][j] = 1;
    }
    return dp[i][j] = 0;
}

bool wildCard(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    // dp[i][j] --> whether txt from (0 to i-1) matches pat (0 to j-1)
    return checkIfMatches(txt, pat, n, m, dp);
}

//DP --> Tabulation
bool wildCard(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length();
    vector<vector<bool>> dp (n+1, vector<bool> (m+1, false));
    // dp[i][j] --> whether txt from (0 to i-1) matches pat (0 to j-1)
    //Write the base Case
    dp[0][0] = true;
    int j = 1;
    while (j <= m){
        if (pat[j-1] == '*') dp[0][j] = true;
        else break;
        j++;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (txt[i-1] == pat[j-1] || pat[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if (pat[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

//Space Optimization
bool wildCard(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length();
    // dp[i][j] --> whether txt from (0 to i-1) matches pat (0 to j-1)
    //Write the base Case
    vector<bool> prev (m+1, false);
    prev[0] = true;
    int j = 1;
    while (j <= m){
        if (pat[j-1] == '*') prev[j] = true;
        else break;
        j++;
    }
    for (int i=1; i<=n; i++){
        vector<bool> curr (m+1, false);
        for (int j=1; j<=m; j++){
            if (txt[i-1] == pat[j-1] || pat[j-1] == '?') {
                curr[j] = prev[j-1];
            }
            else if (pat[j-1] == '*'){
                curr[j] = prev[j] || curr[j-1];
            }
        }
        prev = curr;
    }
    return prev[m];
}

