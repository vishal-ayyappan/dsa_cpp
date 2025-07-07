#include <bits/stdc++.h>
using namespace std;

//Method 1
//Update the indexes as you go across

int numberOfSubstrings(string s) {
    int n = s.length();
    int aIdx = -1;
    int bIdx = -1;
    int cIdx = -1;
    int i = 0;
    int count = 0;
    while (i < n){
        if (s[i] == 'a') aIdx = i;
        else if (s[i] == 'b') bIdx = i;
        else cIdx = i;
        int minVal = min({aIdx, bIdx, cIdx});
        //If all three are present
        if (minVal != -1){
            count += minVal+1;
        }
        i++;
    }
    return count;
}

//TC - O(N)
//SC - O(1)

//Method 2
//No of subarrays with <= 3 elements - No of subarrays with <= 2 elements

int countNoOfsubstrings(string s, int k){
    int n = s.length();
    //No of subarrays with <= 3 elements
    int left = 0;
    int right = 0;
    int count = 0;
    unordered_map<char,int> mpp;
    while (right < n){
        mpp[s[right]]++;
        while (mpp.size() > k){
            mpp[s[left]]--;
            if (mpp[s[left]] == 0) mpp.erase(s[left]);
            left++;
        }
        if (mpp.size() <= k){
            count += (right-left+1);
        }
        right++;
    }
}

int numberOfSubstrings(string s) {
    return countNoOfsubstrings(s, 3) - countNoOfsubstrings(s, 2);
}

//TC - O(2N)
//SC - O(2N)
