#include <bits/stdc++.h>
using namespace std;

/*
Brute Force
// Generate all the subarrays
*/

int characterReplacement(string s, int k) {
    int n = s.length();
    int maxLen = 0;
    for (int i=0; i<n; i++){
        int hash[26] {0};
        int maxFreq = 0;
        int changes = 0;
        for (int j=i; j<n; j++){
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            changes = (j-i+1) - maxFreq;
            if (changes <= k) maxLen = max(maxLen, j-i+1);
            else break;
        }
    }
    return maxLen;
}

//TC - O(N*N)

//Optimal

//Have a maxFreq that will determine which element is majority for that window

int characterReplacement(string s, int k) {
    int n = s.length();
    int left = 0;
    int right = 0;
    int maxFreq = 0;
    int maxLen = 0;
    int hash[26] {0};
    while (right < n){
        hash[s[right] - 'A']++;
        maxFreq = max(maxFreq, hash[s[right] - 'A']);
        int changes = (right-left+1) - maxFreq;
        while (changes > k){
            hash[s[left] - 'A']--;
            //Find updated max Frequency
            int mFreq = 0;
            for (int i=0; i<26; i++) mFreq = max(mFreq, hash[i]);
            //Move one step left
            left++;
            int change_new = (right-left+1) - mFreq;
            if (change_new <= k) break;
        }
        if (changes <= k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}

//TC - O(N)
//SC - O(1)

