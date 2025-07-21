#include <bits/stdc++.h>
using namespace std;

//Edit Distance

//Explore all the possibilities

//DP --> Memoization
int getMinOperations(string& word1, string& word2, int idx1, int idx2, vector<vector<int>>& dp){
    //Base Cases
    if (idx1 < 0 && idx2 < 0) INT_MAX;
    //If word1 gets exhausted (You have to insert the rest of word2)
    if (idx1 < 0) return idx2+1;
    //If word2 is exhausted (ie, you got the match, delete the rest of s1)
    if (idx2 < 0) return idx1+1;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    //Explore all the possibilities
    if (word1[idx1] == word2[idx2]) dp[idx1][idx2] =  getMinOperations(word1, word2, idx1-1, idx2-1, dp);
    else{
        //1. Insertion
        int insertion = 1 + getMinOperations(word1, word2, idx1, idx2-1, dp);
        //2. Deletion
        int deletion = 1 + getMinOperations(word1, word2, idx1-1, idx2, dp);
        //3. Replacement
        int replacement = 1 + getMinOperations(word1, word2, idx1-1, idx2-1, dp);
        dp[idx1][idx2] = min({insertion, deletion, replacement});
    }
    return dp[idx1][idx2];
}

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    if (n == 0) return m;
    if (m == 0) return n;
    //Create a DP array
    //dp[i][j] --> represents minimum operations to get s1 (0 to i-1) to s2 (0 to j-1)
    vector<vector<int>> dp (n, vector<int> (m, -1));
    getMinOperations(word1, word2, n-1, m-1, dp);
    return dp[n-1][m-1];
}

//DP --> Tabulation
int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    if (n == 0) return m;
    if (m == 0) return n;
    //Create a DP array
    //dp[i][j] --> represents minimum operations to get s1 (0 to i) to s2 (0 to j)
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    //Declare Base Cases
    //If word2 is empty, Delete all the char in word1
    for (int i=0; i<=n; i++) dp[i][0] = i;
    //If word1 is empty, insert all the char of word2 in word1
    for (int j=0; j<=m; j++) dp[0][j] = j;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            //If the character matches
            if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int insertion = 1 + dp[i][j-1];
                int deletion = 1 + dp[i-1][j];
                int replacement = 1 + dp[i-1][j-1];
                dp[i][j] = min({insertion, deletion, replacement});
            }
        }
    }
    return dp[n][m];
}

//DP --> Space Optimization
int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    if (n == 0) return m;
    if (m == 0) return n;
    vector<int> dp (m+1, 0);
    //If word1 is empty, insert all the char of word2 in word1
    for (int j=0; j<=m; j++) dp[j] = j;
    for (int i=1; i<=n; i++){
        vector<int> curr (m+1);
        curr[0] = i;
        for (int j=1; j<=m; j++){
            //If the character matches
            if (word1[i-1] == word2[j-1]) curr[j] = dp[j-1];
            else{
                int insertion = 1 + curr[j-1];
                int deletion = 1 + dp[j];
                int replacement = 1 + dp[j-1];
                curr[j] = min({insertion, deletion, replacement});
            }
        }
        dp = curr;
    }
    return dp[m];
}

