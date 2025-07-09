#include <bits/stdc++.h>
using namespace std;

//Longest Substring with K Uniques

/*
Use map to store the value and the frequnecy
*/

//Exactly K distinct elements

int longestKSubstr(string &s, int k) {
    int n = s.length();
    int left = 0;
    int right = 0;
    int maxLen = 0;
    unordered_map<char, int> mpp;
    while (right < n){
        mpp[s[right]]++;
        while (mpp.size() > k){
            mpp[s[left]]--;
            if (mpp[s[left]] == 0){
                mpp.erase(s[left]);
            }
            left++;
        }
        if (mpp.size() <= k){
            maxLen = max(maxLen, right-left+1);
        }
        right++; 
    }  
    if (mpp.size() < k) return -1;
    return maxLen;
}

//TC - O(N)
//SC - O(N)

