#include <bits/stdc++.h>
using namespace std;

//Palindrome Partitioning II
//Find the minimum no of cuts to make the string Palindrome.
//No of palindromes - 1 --> no of cuts

bool isPalindrome(string& s, int i, int j){
    while (i <= j){
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int getMinDP(string& s, int i, vector<int>& dp1){
    if (i == s.length()) return 0;
    if (dp1[i] != -1) return dp1[i];
    int ways = INT_MAX;
    for (int k=i; k<s.length(); k++){
        if (isPalindrome(s, i, k)){
            int newWays = 1 + getMinDP(s, k+1, dp1);
            ways = min(ways, newWays);
        }
    }
    return dp1[i] = ways;
}

int minCut(string s) {
    int n = s.length();
    vector<int> dp1 (n, -1);
    return getMinDP(s, 0, dp1) - 1;
}

//DP --> Tabulation
int minCut(string s) {
    int n = s.length();
    vector<int> dp (n+1, -1);
    //Base Case
    dp[n] = 0;
    for (int i=n-1; i>=0; i--){
        int ways = INT_MAX;
        for (int k=i; k<n; k++){
            if (isPalindrome(s, i, k)){
                int newWays = 1 + dp[k+1];
                ways = min(ways, newWays);
            }
        }
        dp[i] = ways;
    }
    return dp[0]-1;
}



