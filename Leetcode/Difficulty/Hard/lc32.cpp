#include <bits/stdc++.h>
using namespace std;

//Longest Valid Parentheses

int longestValidParentheses(string s) {
    int n = s.length();
    int maxLen = 0;
    int left = 0;
    int right = 0;
    for (int i=0; i<n; i++){
        if (s[i] == '(') left++;
        else right++;
        if (left == right){
            maxLen = max(maxLen, 2*left);
        }
        //If invalid combination
        else if (right > left){
            left = 0;
            right = 0;
        }
    }
    left = 0;
    right = 0;
    for (int i=n-1; i>=0; i--){
        if (s[i] == '(') left++;
        else right++;
        if (left == right){
            maxLen = max(maxLen, 2*left);
        }
        if (left > right){
            left = 0;
            right = 0;
        }
    }
    return maxLen;
}