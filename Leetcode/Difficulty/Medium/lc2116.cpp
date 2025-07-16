#include <bits/stdc++.h>
using namespace std;

//Check if Parenthesis string can be valid
bool canBeValid(string s, string locked) {
    int n = s.length();
    //Odd length cant be valid
    if (n%2 == 1) return false;
    int i = 0;
    //left to right pass
    int open = 0; 
    int freeChars = 0;
    while (i < n){
        if (locked[i] == '1'){
            if (s[i] == '(') open++;
            else open--;
        }
        else freeChars++;
        if (open + freeChars < 0) return false;
        i++;
    }

    //Right to left
    i = n-1;
    int close = 0; 
    freeChars = 0;
    while (i >= 0){
        if (locked[i] == '1'){
            if (s[i] == ')') close++;
            else close--;
        }
        else freeChars++;
        if (close + freeChars < 0) return false;
        i--;
    }
    return true;
}

//TC - O(2*N)
//SC - O(1)