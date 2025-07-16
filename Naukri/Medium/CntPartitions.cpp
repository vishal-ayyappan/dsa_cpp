#include <bits/stdc++.h>
using namespace std;

//Count Partitions with difference K

int getCount(vector<int>& arr, int idx, int target){
    if (idx == 0){
        if (arr[idx] == 0 && target == 0) return 2;
        if (arr[idx] == target || target == 0) return 1;
        return 0;
    }
    int notPick = getCount(arr, idx-1, target);
    int pick = 0;
    if (target >= arr[idx]) pick = getCount(arr, idx-1, target-arr[idx]);
    return pick + notPick;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), d);
    if (total%2 == 1) return 0;
    int target = total/2;
    int result = getCount(arr, n-1, target);
    return result;
}

//DP --> Memoization
const int mod = 1e9+7;
int getCountDP(vector<int>& arr, int idx, int target, vector<vector<int>>& dp){
    if (idx == 0){
        if (target == 0){
            if (arr[idx] == 0) return 2;
            return 1;
        }  
        if (arr[idx] == target) return 1;
        return 0;
    }
    if (dp[idx][target] != -1) return dp[idx][target];
    int notPick = getCountDP(arr, idx-1, target, dp);
    int pick = 0;
    if (target >= arr[idx]) pick = getCountDP(arr, idx-1, target-arr[idx], dp);
    dp[idx][target] = (pick + notPick)%mod;
    return dp[idx][target];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), d);
    if (total%2 == 1) return 0;
    int target = total/2;
    //Declare a DP array (As the problem involves overlapping sub-intervals)
    //dp[idx][target] -> no of subsets in the range 0 to idx that has the sum 'target'.
    vector<vector<int>> dp (n, vector<int> (total+1, -1));
    getCountDP(arr, n-1, target, dp);
    return dp[n-1][target];
}


//DP --> Tabulation (Bottom Up)
const int mod = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), d);
    if (total%2 == 1) return 0;
    int target = total/2;
    //Declare a DP array (As the problem involves overlapping sub-intervals)
    //dp[idx][target] -> no of subsets in the range 0 to idx that has the sum 'target'.
    vector<vector<int>> dp (n, vector<int> (total+1, 0));
    //Write the base cases
    dp[0][0] = 1;
    if (arr[0] <= target) dp[0][arr[0]] += 1;
    for (int i=1; i<n; i++){
        for (int j=0; j<=target; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if (j >= arr[i]) pick = dp[i-1][j-arr[i]];
            dp[i][j] = (pick + notPick)%mod;
        }
    }
    return dp[n-1][target];
}

//Space Optimization
const int mod = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), d);
    if (total%2 == 1) return 0;
    int target = total/2;
    vector<int> prev (target+1, 0);
    //Write the base cases
    prev[0] = 0;
    if (arr[0] <= target) prev[arr[0]] += 1;
    for (int i=1; i<n; i++){
        vector<int> curr (target+1, 0);
        for (int j=0; j<=target; j++){
            int notPick = prev[j];
            int pick = 0;
            if (j >= arr[i]) pick = prev[j-arr[i]];
            curr[j] = (pick + notPick)%mod;
        }
        prev = curr;
    }
    return prev[target];
}


