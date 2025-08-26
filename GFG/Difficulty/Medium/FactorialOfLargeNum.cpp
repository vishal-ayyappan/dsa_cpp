#include <bits/stdc++.h>
using namespace std;

//Factorial of Large Numbers

//Naive Solution
long long getFactorial(int n){
    if (n == 0) return 1;
    return n * getFactorial(n-1);
}

vector<int> factorial(int n) {
    //Find the factorial, get the digits
    long long fact = getFactorial(n);
    vector<int> ans;
    while (fact > 0){
        int dig = (int) fact % 10;
        ans.push_back(dig);
        fact = fact/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//The Optimal Solution is too difficult to think of (You have to kinda solve it beforehand to know this)

//Easy intuition (Do the standard multiplication we do normally where the digits are in the array)
vector<int> factorial(int n) {
    vector<int> ans;
    if (n == 0) return {1};
    ans.push_back(1);
    for (int i=2; i<=n; i++){
        int size = ans.size();
        int carry = 0;
        for (int j=0; j<size; j++){
            int val = ans[j]*i + carry;
            carry = val/10;
            int dig = val%10;
            ans[j] = dig;
        }
        while (carry){
            int dig = carry%10;
            ans.push_back(dig);
            carry = carry/10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


