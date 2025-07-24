#include <bits/stdc++.h>
using namespace std;

//Longest Palindromic Substring (Generate all the substrings and then find the longest)

//DP --> Memoization

//Check if it is a palindrome.
int isPalindrome(string& s, int i, int j, vector<vector<int>>& dp){
    if (i >= j) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) dp[i][j] = isPalindrome(s, i+1, j-1, dp);
    else dp[i][j] = 0;
    return dp[i][j];
}

string longestPalindrome(string s) {
    //Generate all the substrings and then check
    int n = s.length();
    //dp[i][j] --> returns whether the array from range (i to j) is palindrome.
    vector<vector<int>> dp (n, vector<int> (n, -1));
    int maxLen = 0;
    int startIndex = 0;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if (isPalindrome(s, i, j, dp)){
                if (j-i+1 > maxLen){
                    maxLen = j-i+1;
                    startIndex = i;
                }
            }
        }
    }
    return s.substr(startIndex, maxLen);
}

//DP --> Tabulation
string longestPalindrome(string s) {
    //Generate all the substrings and then check
    int n = s.length();
    //dp[i][j] --> returns whether the array from range (i to j) is palindrome.
    vector<vector<bool>> dp (n, vector<bool> (n, false));
    //Base Case
    int maxLength = 1;
    int startIndex = 0;
    //If i == j
    for (int i=0; i<n-1; i++) dp[i][i] = 1;
    //String of length 2
    for (int i=0; i<n-1; i++){
        if (s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            maxLength = 2;
            startIndex = i;
        }
        else dp[i][i+1] = 0;
    }
    //Other lengths
    for (int i=n-3; i>=0; i--){
        for (int j=n-1; j>=i+2; j--){
            if (dp[i+1][j-1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (j-i+1 > maxLength){
                    maxLength = j-i+1;
                    startIndex = i;
                }
                
            }
        }
    }
    return s.substr(startIndex, maxLength);
}

//TC - O(N*N)
//SC - O(N*N)
