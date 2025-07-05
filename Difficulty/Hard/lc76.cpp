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