#include <bits/stdc++.h>
using namespace std;

//Using recursion

void getCount(int n, int& count){
    if (n < 0) return;
    if (n == 0){
        count++;
        return;
    }
    getCount(n-1, count);
    getCount(n-2, count);
}

int climbStairs(int n) {
    int count = 0;
    getCount(n, count);
    return count;
}


//Using memoization (The array will store the count of the possible ways)
int getCount1(int n, vector<int>& dp){
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = getCount1(n-1, dp) + getCount1(n-2, dp);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp (n+1, -1);
    int count = getCount1(n, dp);
    return count;
}

//Using Tabulation
int climbStairs(int n) {
    vector<int> dp (n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp.back();
}

//Space Optimization
int climbStairs(int n) {
    int prev = 1;
    int secondprev = 1;
    for (int i=2; i<=n; i++){
        int curr = prev + secondprev;
        secondprev = prev;
        prev = curr;
    }
    return prev;
}

