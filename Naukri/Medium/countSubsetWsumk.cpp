#include <bits/stdc++.h>
using namespace std;

//Count Subsets with Sum K

//Recursive
// f(idx, target) tells the number of subsequences in the range 0 to idx that has sum == target.
const int mod = 1e9 + 7;

int getWays(vector<int>& arr, int idx, int target){
    //Base Cases
    if (target == 0) return 1;
    if (target < 0 || idx < 0) return 0;
    int notPick = getWays(arr, idx-1, target);
    int pick = getWays(arr, idx-1, target-arr[idx]);
    return (pick + notPick)%mod;
}

int findWays(vector<int>& arr, int k){
	int n = arr.size();
    return getWays(arr, n-1, k);
}


//DP --> memoization (As it contains overlapping subproblems)
int getWaysDP(vector<int>& arr, int idx, int target, vector<vector<int>>& dp){
    if (idx == 0){
        if (arr[idx] == 0 && target == 0) return 2;
        if (target == 0 || arr[idx] == target) return 1;
        return 0;
    }
    if (dp[idx][target] != -1) return dp[idx][target];
    int notPick = getWaysDP(arr, idx-1, target, dp);
    int pick = 0;
    if(target >= arr[idx]) pick = getWaysDP(arr, idx-1, target-arr[idx], dp);
    dp[idx][target] = (pick+notPick)%mod;
    return dp[idx][target];
}

int findWays(vector<int>& arr, int k){
	int n = arr.size();
    //Declare a DP array
    vector<vector<int>> dp (n, vector<int> (k+1, -1));
    getWaysDP(arr, n-1, k, dp);
    return dp[n-1][k];
}

//DP --> Tabulation
int findWays(vector<int>& arr, int k){
    int n = arr.size();
    //Declare a DP array
    vector<vector<int>> dp (n, vector<int> (k+1, 0));
    //Write down the base cases
    //DP [i][j] represents the number of subsets in the range 0 to i, that has sum j
    dp[0][0] = 1;
    if (arr[0] <= k) dp[0][arr[0]] += 1;
    for (int i=1; i<n; i++){
        for (int target=0; target<=k; target++){
            int notPick = dp[i-1][target];
            int pick = 0;
            if (target >= arr[i]) pick = dp[i-1][target-arr[i]];
            dp[i][target] = (pick+notPick)%mod;
        }
    }
    return dp[n-1][k];
}
