#include <bits/stdc++.h>
using namespace std;

//Edit Distance
int getMinOperations(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
    //Base Case
    if (i == 0 && j == 0) return 0;
    //If string 2 is matched, delete the rest of string 1
    if (j == 0) return i;
    //If string 1 is done with and string 2 still remains, insert the rest
    if (i == 0) return j;
    //If the problem is already solved
    if (dp[i][j] != -1) return dp[i][j];
    //Check if character matches
    if (s1[i-1] == s2[j-1]) dp[i][j] =  getMinOperations(s1, s2, i-1, j-1, dp);
    //If it doesnt
    else{
        int insert = getMinOperations(s1, s2, i, j-1, dp);
        int replace = getMinOperations(s1, s2, i-1, j-1, dp);
        int del = getMinOperations(s1, s2, i-1, j, dp);
        dp[i][j] = min({insert, replace, del}) + 1;
    }
    return dp[i][j];
}

int editDistance(string& s1, string& s2) {
    //You have to convert s1 to s2
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    // dp[i][j] --> no of operations required to go from s1 (0 to i-1) and s2 (0 to j-1)
    getMinOperations(s1, s2, n, m, dp);
    return dp[n][m];
}

//DP --> Tabulation
int editDistance(string& s1, string& s2) {
    //You have to convert s1 to s2
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n+1, vector<int> (m+1, INT_MAX));
    // dp[i][j] --> no of operations required to go from s1 (0 to i-1) and s2 (0 to j-1)
    //Base Case
    //Deleting the rest of string 1
    for (int i=0; i<=n; i++) dp[i][0] = i;
    //Insertion of the rest of string 2
    for (int j=0; j<=m; j++) dp[0][j] = j;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int ins = dp[i][j-1];
                int del = dp[i-1][j];
                int repl = dp[i-1][j-1];
                dp[i][j] = 1 + min({ins, del, repl});
            }
        }
    }
    return dp[n][m];
}

