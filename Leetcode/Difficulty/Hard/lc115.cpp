#include <bits/stdc++.h>
using namespace std;

//Count Distinct Subsequences

//Recursive Solution
//f(idx1, idx2) --> No of subsequnces of s2 (0 to idx2) in s1 (0 to idx1)
int getDistinct(string s, string t, int idx1, int idx2){
    if (idx2 < 0) return 1;
    if (idx1 < 0) return 0;
    //If character matches
    if (s[idx1] == t[idx2]){
        //You either pick and reduces both or not choose and look for it in reduces s
        return getDistinct(s, t, idx1-1, idx2-1) + getDistinct(s, t, idx1-1, idx2);
    }
    else return getDistinct(s, t, idx1-1, idx2);
}

int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    return getDistinct(s, t, n-1, m-1);
}

//DP --> Memoization
int getDistinctDP(string s, string t, int idx1, int idx2, vector<vector<int>>& dp){
    if (idx2 < 0) return 1;
    if (idx1 < 0) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if (s[idx1] == t[idx2]) dp[idx1][idx2] = getDistinctDP(s,t,idx1-1,idx2-1,dp) + getDistinctDP(s,t,idx1-1,idx2,dp);
    else dp[idx1][idx2] = getDistinctDP(s,t,idx1-1,idx2,dp);
    return dp[idx1][idx2];
}

int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    //Declare a DP array
    //dp[i][j] --> no of subsequences of s2 (0 to j) in s1 (0 to i)
    vector<vector<int>> dp (n, vector<int> (m, -1));
    getDistinctDP(s, t, n-1, m-1, dp);
    return dp[n-1][m-1];
}

//DP --> Tabulation
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    //Declare a DP array
    //dp[i][j] --> no of subsequences of s2 (0 to j-1) in s1 (0 to i-1)
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    //Base Cases
    for (int i=0; i<=n; i++) dp[i][0] = 1;
    //Recursive Calls
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}

//DP --> Space Optimization
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<int> prev (m+1, 0);
    prev[0] = 1;
    //Recursive Calls
    for (int i=1; i<=n; i++){
        vector<int> curr (m+1);
        curr[0] = 1;
        for (int j=1; j<=m; j++){
            if (s[i-1] == t[j-1]){
                curr[j] = prev[j-1] + prev[j];
            }
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[m];
}

//DP --> Further Space Optimization
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<unsigned long long> prev (m+1, 0);
    prev[0] = 1;
    //Recursive Calls
    for (int i=1; i<=n; i++){
        for (int j=m; j>0; j--){
            if (s[i-1] == t[j-1]){
                prev[j] += prev[j-1];
            }
        }
    }
    return (int)prev[m];
}


//Understand how the DP table is filled


