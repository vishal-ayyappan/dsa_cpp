#include<bits/stdc++.h>
using namespace std;

//Minimum Window Substring

//Naive approach
/*
0/ Generate all the substrings
*/

string minWindow(string s, string t) {
    int m = s.length();
    int n = t.length();
    unordered_map<char, int> mpp;
    for (int i=0; i<n; i++){
        mpp[t[i]]++;
    }
    //Generate all the substrings
    int minVal = INT_MAX;
    int first = 0;
    int last = 0;
    for (int i=0; i<m; i++){
        unordered_map<char, int> mpp_ = mpp;
        int remaining = t.length();
        for (int j=i; j<m; j++){
            if (mpp_.find(s[j]) != mpp_.end()){
                if (mpp_[s[j]] > 0) remaining--;
                mpp_[s[j]]--;
            }
            if (remaining == 0){
                minVal = min(minVal, j-i+1);
                if (minVal == j-i+1){
                    first = i;
                    last = j;
                }
                break;
            }
            
        }
    }
    if (minVal == INT_MAX) return "";
    string res = s.substr(first, last-first+1);
    return res;
}

//TC - O(N*N)
//SC - O(N)

string minWindow(string s, string t) {
    int n = s.length();
    int m = t.length();
    unordered_map<char, int> mpp;
    //Put all the target string freq in the map
    for (int i=0; i<m; i++){
        mpp[t[i]]++;
    }
    int remaining = m;
    int left = 0;
    int right = 0;
    int minLen = INT_MAX;
    int sIdx = -1;
    while (right < n){
        //Check if this character is present
        if (mpp.find(s[right]) != mpp.end()){
            if (mpp[s[right]] > 0) remaining--;
        }
        mpp[s[right]]--;
        //Once all the characters of t are found, find the minimum window
        while (remaining == 0){
            mpp[s[left]]++;
            if (mpp[s[left]] > 0) remaining++;
            minLen = min(right - left + 1, minLen);
            if (minLen == right-left+1){
                sIdx = left;
            }
            left++;
        }
        right++;
    }
    if (sIdx == -1) return "";
    string res = s.substr(sIdx, minLen);
    return res;
}