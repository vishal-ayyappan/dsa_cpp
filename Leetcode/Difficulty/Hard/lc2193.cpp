#include <bits/stdc++.h>
using namespace std;

//Minimum Number of Moves to Make Palindrome

int minMovesToMakePalindrome(string s) {
    //It is guranteed that it could form a palindrome
    int n = s.length();
    int i = 0;
    int j = n-1;
    int count = 0;
    while (i < j){
        //No Swaps Needed
        if (s[i] == s[j]){
            i++;
            j--;
            continue;
        }
        //Keep s[i] and swap make s[j] == s[i]
        int counti = 0;
        int idxi = j;
        while (idxi > i){
            if (s[idxi] == s[i]) break;
            counti++;
            idxi--;
        }
        //Keep s[j] fixed and swap s[i] to make s[i] == s[j]
        int countj = 0;
        int idxj = i;
        while (idxj <j){
            if (s[idxj] == s[j]) break;
            countj++;
            idxj++;
        }
        //When s[j] is fixed, swap happens
        if (counti > countj){
            for (int p=idxj; p>i; p--){
                swap(s[p], s[p-1]);
            }
            count += countj;
        }
        //When s[i] is fixed, swap happens
        else{
            for (int p=idxi; p<j; p++){
                swap(s[p], s[p+1]);
            }
            count += counti;
        }
        i++;
        j--; 
    }
    return count;
}