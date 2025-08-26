#include <bits/stdc++.h>
using namespace std;

//Longest Common Substring

int getLongestCommonSubstr(string& s1, string& s2, int i, int j, vector<vector<int>>& dp, int& maxi){
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    //Write the recurrence relation
    if (s1[i-1] == s2[j-1]) {
        dp[i][j] = 1 + getLongestCommonSubstr(s1, s2, i-1, j-1, dp, maxi);
        maxi = max(maxi, dp[i][j]);
    }
    else {
        dp[i][j] = 0;
    }
    //Check other ways as well
    getLongestCommonSubstr(s1, s2, i-1, j, dp, maxi);
    getLongestCommonSubstr(s1, s2, i, j-1, dp, maxi);
    return dp[i][j];
}

int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    // dp[i][j] --> LC substring of s1 (0 to i-1) and s2 (0 to j-1)
    int maxi = 0;
    getLongestCommonSubstr(s1, s2, n, m, dp, maxi);
    return maxi;
}

//DP --> Tabulation
int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    // dp[i][j] --> LC substring of s1 (0 to i-1) and s2 (0 to j-1)
    int maxi = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return maxi;
}
