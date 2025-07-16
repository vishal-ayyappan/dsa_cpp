#include <bits/stdc++.h>
using namespace std;

//Minimum Add to make Valid String

int minAddToMakeValid(string s) {
    //2 Traversals
    int n = s.length();
    //For open brackets
    int open = 0;
    int i = 0;
    while (i < n){
        if (s[i] == '(') open++;
        else{
            if (open > 0) open--;
        }
        i++;
    }
    //For Closed Brackets
    int j = n-1;
    int close = 0;
    while (j >= 0){
        if (s[j] == ')') close++;
        else{
            if (close > 0) close--;
        }
        j--;
    }
    return open+close;
}

//TC - O(2N)
//SC - O(1)