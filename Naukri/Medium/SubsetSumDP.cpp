#include <bits/stdc++.h> 
using namespace std;

//Subset sum equal to K

//Recursive solution
//1/ Express the problem in terms of index
//2/ Do the stuff in the index

bool subSum(vector<int>& arr, int idx, int sum){
    //Base Case 
    if (sum == 0) return true;
    if (sum < 0 || idx >= arr.size()) return false;
    //Pick
    if (subSum(arr, idx+1, sum-arr[idx])) return true;
    //Not Pick
    if (subSum(arr, idx+1, sum)) return true;
    return false;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return subSum(arr, 0, k);
}

//One more Variation (Similar structure to pick and nonpick)
bool subSum(vector<int>& arr, int idx, int target){
    //Base Case 
    if (target == 0) return true;
    if (idx == 0){
        if (arr[idx] == target) return true;
        else return false;
    }
    bool notPick = subSum(arr, idx-1, target);
    bool pick = false;
    if (target >= arr[idx]) pick = subSum(arr, idx-1, target-arr[idx]);
    return (pick || notPick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    //f(n-1, target) -> does there exists a target sum from the start to index n-1.
    return subSum(arr, n-1, k);
}

//DP --> Memoization
int subSumDP(vector<int>& arr, int idx, int target, vector<vector<int>>& dp){
    //Base Cases
    if (dp[idx][target] != -1) return dp[idx][target];
    if (target == 0){
        dp[idx][target] = 1;
        return dp[idx][target];
    }
    if (idx == 0){
        if (arr[idx] == target){
            dp[idx][target] = 1;
            return dp[idx][target];
        }
        else{
            dp[idx][target] = 0;
            return dp[idx][target];
        }
    }
    int notPick = subSumDP(arr, idx-1, target, dp);
    int pick = 0;
    if (target >= arr[idx]) pick = subSumDP(arr, idx-1, target-arr[idx], dp);
    if (pick || notPick) dp[idx][target] = 1;
    else dp[idx][target] = 0;
    return dp[idx][target];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    //dp[n-1][target] -> does there exists a target sum from the start to index n-1.
    vector<vector<int>>dp (n, vector<int> (k+1, -1));
    subSumDP(arr, n-1, k, dp);
    if (dp[n-1][k]) return true;
    return false; 
}

//DP --> Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    //dp[n-1][target] -> does there exists a target sum from the start to index n-1.
    vector<vector<bool>> dp (n, vector<bool> (k+1, false));
    //Write the Base Cases
    // Declare true when target == 0
    for (int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i=1; i<n; i++){
        for (int j=1; j<=k; j++){
            bool notpick = dp[i-1][j];
            bool pick = false;
            if (j >= arr[i]) pick = dp[i-1][j-arr[i]];
            dp[i][j] = (pick || notpick);
        }
    }
    return dp[n-1][k];
}

//Space Optimization (It is possible)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    //You only need the prevIdx
    vector<bool> prev (k+1, false);
    //Initializing prev (This is for the first index)
    //The index of prev represents the target that it has to satisfy
    //If target = 0, return true
    prev[0] = true;
    //If the target = 0th index value
    prev[arr[0]] = true;
    for (int i=1; i<n; i++){
        vector<bool> curr (k+1, false);
        curr[0] = true;
        for (int j=1; j<=k; j++){
            bool notpick = prev[j];
            bool pick = false;
            if (j >= arr[i]) pick = prev[j-arr[i]];
            curr[j] = (pick || notpick);
        }
        prev = curr;

    }
    return prev[k];
}

//TC - O(N*K)
//SC - O(K)

