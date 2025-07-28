#include <bits/stdc++.h>
using namespace std;

//Partition Array for Maximum Sum (Front Partition DP)

int getMaxSum(vector<int>& arr, int idx, int k, vector<int>& dp){
    //If the array is exhausted
    if (idx == arr.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
    int currMax = 0;
    int maxSum = 0;
    for (int i=idx; i<idx+k; i++){
        if (i >= arr.size()) continue;
        currMax= max(currMax, arr[i]);
        int size = i - idx + 1;
        int addVal = currMax*size + getMaxSum(arr, i+1, k, dp);
        maxSum = max(maxSum, addVal);
    }
    return dp[idx] = maxSum;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp (n, -1);
    //dp[i] --> maxSum you get from partitioning array (i to n-1) given the length of subarrays is almost k
    getMaxSum(arr, 0, k, dp);
    return dp[0];
}