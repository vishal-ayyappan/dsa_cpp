#include <bits/stdc++.h>
using namespace std;

int LCSubStr(string &str1, string &str2){
    int n = str1.length();
    int m = str2.length();
    //Declare a DP array
    //dp[i][j] --> reprsents LC Subsequnce of str1 (0 to i-1) and str2 (0 to j-1)
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    int maxLen = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen, dp[i][j]);
            }
            else {
                //Has to be contiguous
                dp[i][j] = 0; 
            }
        }
    }
    return maxLen;
}