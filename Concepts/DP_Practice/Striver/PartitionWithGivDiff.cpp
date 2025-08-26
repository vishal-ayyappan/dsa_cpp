#include <bits/stdc++.h>
using namespace std;

//Partitions with Given Difference

int getCount(vector<int>& arr, vector<vector<int>>& dp, int i, int sum){
    //Base Case
    if (i == 0){
        if (sum == 0 && arr[i] == 0) return dp[i][sum] = 2;
        if (sum == 0 || sum == arr[i]) return dp[i][sum] = 1;
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    //Do all the stuff
    int notPick = getCount(arr, dp, i-1, sum);
    int pick = 0;
    if (sum >= arr[i]) pick = getCount(arr, dp, i-1, sum-arr[i]);
    dp[i][sum] = pick + notPick;
    return dp[i][sum];
}

int countPartitions(vector<int>& arr, int d) {
    //This is equivalent to no of subsets with sum (T+D)/2
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    int total_sum = total + d;
    //If you cannot split it into 2
    if (total_sum % 2 == 1) return 0;
    total_sum /= 2;
    vector<vector<int>> dp (n, vector<int> (total_sum+1, -1));
    getCount(arr, dp, n-1, total_sum);
    return dp[n-1][total_sum];
}

//DP --> Tabulation
int countPartitions(vector<int>& arr, int d) {
    //This is equivalent to no of subsets with sum (T+D)/2
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    int total_sum = total + d;
    //If you cannot split it into 2, if it the target is a decimal number
    if (total_sum % 2 == 1) return 0;
    total_sum /= 2;
    vector<vector<int>> dp (n, vector<int> (total_sum+1, -1));
    //Write the base case
    dp[0][0] = 0;
    if (arr[0] <= total_sum) dp[0][arr[0]] += 1;
    for (int i=1; i<n; i++){
        for (int j=0; j<=total_sum; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if (j >= arr[i]) pick = dp[i-1][j-arr[i]];
            dp[i][j] = notPick + pick;
        }
    }
    return dp[n-1][total_sum];
}
