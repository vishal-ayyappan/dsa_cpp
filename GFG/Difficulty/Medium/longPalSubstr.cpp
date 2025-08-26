#include <bits/stdc++.h>
using namespace std;

// Longest Palindromic Substring

bool checkPalindrome(string& s, int i, int j, vector<vector<int>>& dp){
    if (i >= j) return true;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) dp[i][j] = checkPalindrome(s, i+1, j-1, dp);
    else dp[i][j] = false;
    return dp[i][j];
}

string getLongestPal(string &s) {
    int n = s.length();
    vector<vector<int>> dp (n, vector<int> (n, -1));
    int maxLen = INT_MIN;
    int start_idx = -1;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if (checkPalindrome(s, i, j, dp)){
                int len = j-i+1;
                if (len > maxLen){
                    maxLen = len;
                    start_idx = i;
                }
            }
        }
    }
    string ans = s.substr(start_idx, maxLen);
    return ans;
}