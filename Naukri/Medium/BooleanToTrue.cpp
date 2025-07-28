#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int getCount(string& exp, int i, int j, int wantTrue, vector<vector<vector<int>>>& dp){
    //Base Cases
    if (i > j) return 0;
    if (i == j){
        //If we need true
        if (wantTrue == 1){
            if (exp[i] == 'T') return 1;
            return 0;
        }
        //If we need false
        else{
            if (exp[i] == 'F') return 1;
            return 0;
        }
    }
    if (dp[i][j][wantTrue] != -1) return dp[i][j][wantTrue];
    //We partition on the operators
    int ways = 0;
    for (int k=i+1; k<=j-1; k+=2){
        int LeftTrue = getCount(exp, i, k-1, 1, dp);
        int LeftFalse = getCount(exp, i, k-1, 0, dp);
        int RightTrue = getCount(exp, k+1, j, 1, dp);
        int RightFalse = getCount(exp, k+1, j, 0, dp);
        //OR operator
        if (exp[k] == '|'){
            if (wantTrue == 1) ways = (ways + 1LL*LeftTrue*RightTrue + 1LL*LeftTrue*RightFalse + 1LL*LeftFalse*RightTrue)%mod;
            else ways = (ways + 1LL*LeftFalse*RightFalse)%mod;
        }
        //AND Operator
        else if (exp[k] == '&'){
            if (wantTrue == 1) ways = (ways + 1LL*LeftTrue*RightTrue)%mod;
            else ways = (ways + 1LL*LeftFalse*RightFalse + 1LL*LeftTrue*RightFalse + 1LL*LeftFalse*RightTrue)%mod;
        }
        //XOR operator
        else{
            if (wantTrue == 1) ways = (ways + 1LL*LeftTrue*RightFalse + 1LL*LeftFalse*RightTrue)%mod;
            else ways = (ways + 1LL*LeftFalse*RightFalse + 1LL*LeftTrue*RightTrue)%mod;
        }
    }
    return dp[i][j][wantTrue] = ways;
}

int evaluateExp(string & exp) {
    int n = exp.length();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (n,  vector<int> (2, -1)));
    //dp[i][j][k] --> count the no of ways in which the expression can be solved from (i to j) to get 'k' . k(0/1)
    getCount(exp, 0, n-1, 1, dp);
    return dp[0][n-1][1];
}