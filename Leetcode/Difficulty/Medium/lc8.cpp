#include <bits/stdc++.h>
using namespace std;

//String to Integer (atoi)

int myAtoi(string s) {
    int n = s.length();
    int i = 0;
    bool isNegative = false;
    while (i < n){
        if (s[i] == ' '){
            i++;
            continue;
        }
        else if (s[i] == '-'){
            i++;
            isNegative = true;
            break;
        }
        else if (s[i] == '+'){
            i++;
            break;
        }
        else if (isalpha(s[i])) return 0;
        else{
            break;
        }
    }
    if (i == n) return 0;
    long long num = 0;
    while (i < n){
        //Return what is read
        if (isalpha(s[i]) || s[i] == '-' || s[i] == '+' || s[i] == '.' || s[i] == ' ') break;
        int dig = s[i] - '0';
        if (num > INT_MAX/10 || (num == INT_MAX/10 || dig > INT_MAX%10)) {
            if (isNegative) return INT_MIN;
            return INT_MAX;
        }
        num = num*10 + dig;
        i++;  
    }
    if (isNegative) return -num;
    return num;
}