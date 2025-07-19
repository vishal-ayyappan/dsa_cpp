#include <bits/stdc++.h>
using namespace std;

//Recursive Solution
//f(idx1,idx2) --> represents LCS of string1 (0 to idx1) and string2 (0 to idx2)
int getLongest(string& text1, string& text2, int idx1, int idx2){
    if (idx1 < 0 || idx2 < 0) return 0;
    //If Equal
    if (text1[idx1] == text2[idx2]) return 1 + getLongest(text1, text2, idx1-1, idx2-1);
    //If Not Equal
    return max(getLongest(text1, text2, idx1-1, idx2), getLongest(text1, text2, idx1, idx2-1));
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    return getLongest(text1, text2, n-1, m-1);
}

//DP --> Memoization
int getLongestDP(string& text1, string& text2, int idx1, int idx2, vector<vector<int>>& dp){
    if (idx1 < 0 || idx2 < 0) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if (text1[idx1] == text2[idx2]) dp[idx1][idx2] = 1 + getLongestDP(text1, text2, idx1-1, idx2-1, dp);
    else dp[idx1][idx2] = max(getLongestDP(text1, text2, idx1, idx2-1, dp), getLongestDP(text1, text2, idx1-1, idx2, dp));
    return dp[idx1][idx2];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp (n, vector<int> (m, -1));
    getLongestDP(text1, text2, n-1, m-1, dp);
    return dp[n-1][m-1];
}

//DP --> Tabulation
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    //Declare DP array
    //dp[i][j] --> LCS of string (0 to i-1) and string (0 to j-1)
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    //Do what you did on recursion
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m]; 
}

//DP --> Space Optimization
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    //Declare DP array
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    //
    vector<int> prevRow (m+1, 0);
    vector<int> prevCol (n+1, 0);
    //Do what you did on recursion
    for (int i=1; i<=n; i++){
        vector<int> currRow (m+1);
        vector<int> currCol (n+1);
        for (int j=1; j<=m; j++){
            if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m]; 
}



