#include <bits/stdc++.h>
using namespace std;

//Power (x,n)

double myPow(double x, int n) {
    //Iterative
    if (x == 1 || n == 0) return 1;
    if (x == -1 && (n&1)) return -1;
    if (x == -1 && !(n&1)) return 1;
    double result = 1;
    long long exp = abs((long long)n);
    while (exp > 0){
        if (exp%2 == 0){
            x = x*x;
            exp /= 2;
        }
        else{
            result = result*x;
            exp -= 1;
        }
    }
    if (n < 0) return 1/result;
    return result;
}

//Recursive
void getPower(double x, long long exp, double& result){
    //Base Case
    if (exp == 0) return;
    if (exp%2 == 0) getPower(x*x, exp/2, result);
    else {
        result *= x;
        getPower(x, exp-1, result);
    }
}

double myPow(double x, int n) {
    //Iterative
    if (x == 1 || n == 0) return 1;
    if (x == -1 && (n&1)) return -1;
    if (x == -1 && !(n&1)) return 1;
    long long exp = abs((long long)n);
    double result = 1;
    getPower(x, exp, result);
    if (n<0) return 1/result;
    return result;
}
