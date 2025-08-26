#include <bits/stdc++.h>
using namespace std;

//Ways to Express an Integer as Sum of Powers 

// 0/ Compute the powers of all the numbers from 1 to wherever it breaks.
// 1/ Do the pick and not pick method to get the answer

const int MOD = 1e9 + 7;

long long power (int n, int x){
    long long result = 1;
    if (n == 0) return result;
    while (x > 0){
        if (x%2 == 0){
            n *= n;
            x = x/2;
        }
        else{
            result *= n;
            x = x-1;
        }
    }
    return result;
}

vector<long long> getPowers(int n, int x){
    vector<long long> ans;
    int i = 0;
    while (true){
        long long val = power(i, x);
        if (val > n) break;
        ans.push_back(val);
        i++;
    }
    return ans;
}

int getWays(vector<vector<int>>& dp, long long n, int el, vector<long long>& powers){
    if (n == 0) return 1;
    if (el >= powers.size()) return 0;
    if (dp[n][el] != -1) return dp[n][el];
    //Pick
    long long val = n - powers[el];
    int left = 0;
    if (val >= 0) left += getWays(dp, val, el+1, powers)%MOD;
    //Not Pick
    int right = getWays(dp, n, el+1, powers)%MOD;
    dp[n][el] = (left + right) % MOD;
    return dp[n][el];
}

int numberOfWays(int n, int x) {
    // dp[i][j] --> number of ways to get to i, with the element being j
    vector<long long> powers = getPowers(n, x);
    int size = powers.size();
    vector<vector<int>> dp (n+1, vector<int> (size, -1));
    int ways = getWays(dp, n, 1, powers);
    return ways;
}


// DP --> Tabulation
int numberOfWays(int n, int x) {
    // dp[i][j] --> number of ways to get to i, with the element being j
    vector<long long> powers = getPowers(n, x);
    int size = powers.size();
    vector<vector<int>> dp (n+1, vector<int> (size, 0));
    //Bottom up
    for (int i=0; i<size; i++) dp[0][i] = 1;
    for (int power=0; power<powers.size(); power++){
        long long p = powers[power];
        for (int sum=1; sum<=n; sum++){
            //Not pick
            int notPick = (power >= 1) ? dp[sum][power-1] : 0;
            //Pick
            int pick = 0;
            if (sum >= p){
                if (power >= 1){
                    pick = dp[sum - p][power-1];
                }
                else{
                    if (sum == p) pick = 1;
                    else pick = 0;
                }
            }
            dp[sum][power] = (pick + notPick)%MOD;
        }
    }
    return dp[n][size-1];
}
