#include <bits/stdc++.h>
using namespace std;

/*
Be very Careful with the edge cases
*/

int reverse(int x) {
    int p = x;
    int reverse = 0;
    while (p != 0){
        int num = p%10;
        //Important
        if (reverse < INT_MIN/10 || (reverse == INT_MIN && num < -8)) return 0;
        if (reverse > INT_MAX/10 || (reverse == INT_MAX && num > 7)) return 0;
        reverse = reverse*10 + num;
        p = p/10;
    }
    return reverse;
}

//TC O(log10(x))
//SC O(1)
