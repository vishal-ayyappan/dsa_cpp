#include <bits/stdc++.h>
using namespace std;

//Longest Palindrome subsequence

int longestPalindromeSubseq(string s) {
    int n = s.length();
    string s1 = s;
    reverse(s1.begin(), s1.end());
    string s2 = s;
    //Declare a DP array,
    //dp[i][j] --> LCS of string s1 (0 to i-1) and s2 (0 to j-1)
    vector<vector<int>> dp (n+1, (vector<int> (n+1, 0)));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

//TC - O(N*N)
//SC - O(N*N) Can be further space optimized to O(N)