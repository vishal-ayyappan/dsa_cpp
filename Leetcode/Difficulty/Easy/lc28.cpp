#include <bits/stdc++.h>
using namespace std;

/*
Simple Logic
*/

int strStr(string haystack, string needle) {
    int m = haystack.length();
    int n = needle.length();
    if (n > m) return -1;
    int i = 0;
    while(i < m){
        int j = 0;
        int k = i;
        while (j<n){
            if (haystack[k] != needle[j]) break;
            j++;
            k++;
        }
        if (j == n) return i;
        i++;
    }
    return -1;
}

//TC O(N)
//SC O(1)