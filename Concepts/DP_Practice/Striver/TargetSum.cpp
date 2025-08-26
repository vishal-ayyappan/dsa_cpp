#include <bits/stdc++.h>
using namespace std;

//Target Sum (Good Question)

//THis is similar to find the no of partitions where the difference is target

//One Way
const int MOD = 1e9 + 7;

int getWays(vector<int>& A, int i, int target, vector<unordered_map<int, int>>& dp){
    if (i < 0){
        if (target == 0) return 1;
        return 0;
    }
    if (dp[i].find(target) != dp[i].end()) return dp[i][target];
    //Do all the stuff
    //Either you subtract the value
    int subtract = getWays(A, i-1, target+A[i], dp);
    int add = getWays(A, i-1, target-A[i], dp);
    dp[i][target] = (add + subtract) % MOD;
    return dp[i][target];
}

long long findTargetSumWays(int n, vector<int>& A, int target) {
    int sum = accumulate(A.begin(), A.end(), 0);
    vector<unordered_map<int, int>> dp (n);
    // dp[i][j] = number of ways to get to j from the values 0 to i;
    getWays(A, n-1, target, dp);
    return dp[n-1][target];
}

//DP --> Tabulation (pick/notPick)
long long findTargetSumWays(int n, vector<int>& A, int target) {
    int sum = accumulate(A.begin(), A.end(), target);
    if (sum < 0 || sum%2 == 1) return 0;
    int target_sum = sum/2;
    vector<vector<long long>> dp (n, vector<long long> (target_sum+1, 0));
    //You have to offset every value by -sum
    dp[0][0] = 1;
    if (A[0] <= target_sum) dp[0][A[0]] += 1;
    for (int i=1; i<n; i++){
        for (int j=0; j<=target_sum; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if (j >= A[i]) pick = dp[i-1][j-A[i]];
            dp[i][j] = (pick + notPick)%MOD;
        }
    }
    return dp[n-1][target_sum];
}

