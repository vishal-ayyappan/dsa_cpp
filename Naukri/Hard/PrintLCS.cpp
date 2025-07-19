#include <bits/stdc++.h>
using namespace std;


//DP Solution
//Get the longest common subsequnce table filled up and then backtrack
string findLCS(int n, int m,string &s1, string &s2){
    string res;
	vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }	
    if (dp[n][m] == 0) return "";
    //Now BackTracking
    int i = n;
    int j = m;
    while (i > 0 && j > 0){
        if (s1[i-1] == s2[j-1]){
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else j--;
    }
    reverse(res.begin(), res.end());
    return res;
}