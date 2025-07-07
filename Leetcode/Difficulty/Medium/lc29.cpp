#include <bits/stdc++.h>
using namespace std;

//Divide 2 integers

/*
0/ For the result to be negtive, there should be only on negative sign
1/ Take care of the edge cases
*/

int divide(int dividend, int divisor) {
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if (dividend != INT_MIN) return -dividend;
        else return INT_MAX;
    }
    bool isNegative = false;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) isNegative = true;
    long long p = abs((long long)dividend);
    long long q = abs((long long)divisor);
    long long count = 0;
    while (p >= q){
        long long val = q;
        int counti = 1;
        while ((val<<1) <= p){
            val = val<<1;
            counti = counti<<1;
        }
        p -= val;
        count += counti;
    }
    if (isNegative) return (int)-count;
    if (count > INT_MAX) return INT_MAX;
    return (int)count;
}

//TC - O(log(a/b))
//SC - O(1)