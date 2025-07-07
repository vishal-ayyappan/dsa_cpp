#include <bits/stdc++.h>
using namespace std;

//Longest Substring Without Repeating Characters

/*
Sliding window
0/ Use a hashmap to check if it the string contains the character
*/

int lengthOfLongestSubstring(string s) {
    //Use a visited array
    vector<bool> visited (256, false);
    int n = s.length();
    int left = 0;
    int right = 0;
    int maxLen = 0;
    while (right < n){
        if (visited[s[right]] == false){
            maxLen = max(maxLen, right - left + 1);
        }
        else{
            while (visited[s[right]] == true){
                visited[s[left]] = false;
                left++;
            }
        }  
        visited[s[right]] = true;
        right++; 
    }
    return maxLen;
}

//TC - O(N)
//SC - O(256)

//Another approach

/*
Using hash table to map the occurence of the character
*/

int lengthOfLongestSubstring(string s) {
    //Use a Hash Table  
    int n = s.length();
    unordered_map<char,int> mpp;
    int left = 0;
    int right = 0;
    int maxLen = 0;
    while (right < n){
        if (mpp.find(s[right]) != mpp.end()){
            int idx = mpp[s[right]];
            left = max(left, idx+1);
        }
        mpp[s[right]] = right;
        maxLen = max(maxLen, right-left+1);
        right++;
    }
    return maxLen;
}

//TC - O(N)
//SC - O(N)