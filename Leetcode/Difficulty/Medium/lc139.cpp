#include <bits/stdc++.h>
using namespace std;

//Word Break

int isPossible(string s, int start, unordered_map<string, bool>& mpp, vector<int>& dp){
    if (start == s.length()) return 1;
    if (dp[start] != -1) return dp[start];
    string temp;
    for (int i=start; i<s.length(); i++){
        temp.push_back(s[i]);
        if (mpp.find(temp) != mpp.end()){
            if (isPossible(s, i+1, mpp, dp)) return dp[start] = 1;
        }
    }
    return dp[start] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
    //Store the words in a map
    unordered_map<string, bool> mpp;
    int n = wordDict.size();
    int m = s.length();
    vector<int> dp (m, -1);
    for (int i=0; i<n; i++) mpp[wordDict[i]] = true;
    isPossible(s, 0, mpp, dp);
    if (dp[0] == 1) return true;
    return false;
}