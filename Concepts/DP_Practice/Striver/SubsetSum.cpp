#include <bits/stdc++.h>
using namespace std;

//Subset Sum
int checkSubsetSum(vector<int>& arr, vector<vector<int>>& dp, int i, int sum){
    //Base Case
    if (sum == 0) return 1;
    if (i < 0) return 0;
    if (dp[i][sum] != -1) return dp[i][sum];
    //If you do not pick
    int notPick = checkSubsetSum(arr, dp, i-1, sum);
    int pick = 0;
    if (sum - arr[i] >= 0) pick = checkSubsetSum(arr, dp, i-1, sum-arr[i]);
    //If any one gives you the target, you return true
    dp[i][sum] = pick | notPick;
    return dp[i][sum];
}

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (sum+1, -1));
    // dp[i][j] --> check if there exists a sum 'j' in the array 0 to i.
    checkSubsetSum(arr, dp, n-1, sum);
    if (dp[n-1][sum] == 1) return true;
    return false;
}


//DP --> Tabulation
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp (n, vector<bool> (sum+1, 0));
    // dp[i][j] --> check if there exists a sum 'j' in the array 0 to i.
    //Write the base case
    for (int i=0; i<n; i++) dp[i][0] = 1;
    //If there is one element in the array, and if the sum is arr[0].
    if (arr[0] <= sum) dp[0][arr[0]] = 1;
    //Do the recursion calls
    for (int i=1; i<n; i++){
        for (int j=1; j<=sum; j++){
            //NotPick
            bool notPick = dp[i-1][j];
            bool pick = false;
            if (j - arr[i] >= 0) pick = dp[i-1][j-arr[i]];
            dp[i][j] = pick | notPick;
        }
    }
    return dp[n-1][sum];
}
