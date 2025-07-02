#include <bits/stdc++.h>
using namespace std;

/*
Again, straighforward question, but be extra careful when dealing with edgge conditions
*/

bool isPalindrome(int x) {
    //Edge conditions
    if (x < 0) return false;
    if (x/10 == 0) return true;
    if (x%10 == 0) return false;
    int p = x;
    int reverse = 0;
    while (p > reverse){
        int digit = p%10;
        reverse = reverse*10 + digit;
        p = p/10;
    }
    if (reverse == p || reverse/10 == p) return true;
    return false;
}