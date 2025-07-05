#include <bits/stdc++.h>
using namespace std;

/*
0/ Map the frequency of occurence.
*/

int characterReplacement(string s, int k) {
    int n = s.length();
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int count = 0;
    unordered_map<char, int> mpp;
    while (right < n){
        mpp[s[right]]++;
        if (s[right] != s[left]) count++;
        while (count > k){
            mpp[s[left]]--;
            if (mpp[s[left]] == 0){
                mpp.erase(mpp[s[left]]);
                count--;
            }
            left++;
        }
        if (count <= k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}