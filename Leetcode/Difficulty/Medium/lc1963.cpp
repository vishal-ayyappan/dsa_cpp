#include <bits/stdc++.h>
using namespace std;

//Minimum number of swaps to make the string balanced

int minSwaps(string s) {
    //Two Pointer with greedy
    int n = s.length();
    int open = 0;
    int imbalance = 0;
    for (int i=0; i<n; i++){
        if (s[i] == '[') open++;
        else open--;
        if (open < 0){
            imbalance++;
            open = 0;
        }
    }
    return (imbalance+1)/2;
}