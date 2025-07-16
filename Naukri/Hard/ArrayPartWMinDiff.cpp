#include <bits/stdc++.h>
using namespace std;

//Array partition with minimum difference (Size of subsets does not matter)
bool getSum(vector<int>& arr, int idx, int target){
    if (target == 0) return true;
    if (idx == 0){
        if (arr[idx] == target) return true;
        return false;
    }
    bool notPick = getSum(arr, idx-1, target);
    bool pick = false;
    if (target >= arr[idx]) pick = getSum(arr, idx-1, target-arr[idx]);
    return (notPick || pick);
}

int minSubsetSumDifference(vector<int>& arr, int n){
	//As we need min difference, it would be better if both the subsets are close to S/2
    int total = 0;
    for (int i=0; i<n; i++) total += arr[i];
    int max_range = total/2;
    int result = INT_MAX;
    for (int target=0; target<=max_range; target++){
        //f(idx,target) gives you if the sum of any subsequence from 0 to idx equals target
        bool val = getSum(arr, n-1, target);
        if (val){
            result = min(result, abs(total - 2*target));
        }
    }
    return result;
}

//DP --> memoization
int getSumDP(vector<int>& arr, int idx, int target, vector<vector<int>>& dp){
    //Base Cases
    if (dp[idx][target] != -1) return dp[idx][target];
    if (target == 0){
        dp[idx][target] = 1;
        return dp[idx][target];
    }
    if (idx == 0){
        int val;
        if (arr[idx] == target) val = 1;
        else val = 0;
        dp[idx][target] = val;
        return dp[idx][target];
    }
    int notPick = getSumDP(arr, idx-1, target, dp);
    int pick = false;
    if (target >= arr[idx]) pick = getSumDP(arr, idx-1, target-arr[idx], dp);
    dp[idx][target] = (pick || notPick);
    return dp[idx][target];
}

int minSubsetSumDifference(vector<int>& arr, int n){
	//As we need min difference, it would be better if both the subsets are close to S/2
    int total = 0;
    for (int i=0; i<n; i++) total += arr[i];
    int max_range = total/2;
    //Declare a DP array
    vector<vector<int>> dp (n, vector<int> (max_range+1, -1));
    int result = INT_MAX;
    for (int target=0; target<=max_range; target++){
        //f(idx,target) gives you if the sum of any subsequence from 0 to idx equals target
        getSumDP(arr, n-1, target, dp);
        //If there exists a subsequence in the range (0,n-1) whose sum equals target
        if (dp[n-1][target] != 0){
            result = min(result, abs(total - 2*target));
        }
    }
    return result;
}


//DP --> Tabulation
int minSubsetSumDifference(vector<int>& arr, int n){
	//As we need min difference, it would be better if both the subsets are close to S/2
    int total = 0;
    for (int i=0; i<n; i++) total += arr[i];
    int max_range = total/2;
    //Declare a DP array
    vector<vector<bool>> dp (n, vector<bool> (max_range+1, false));
    //Write the Base Cases
    for (int i=0; i<n; i++) dp[i][0] = true;
    if (arr[0] <= max_range) dp[0][arr[0]] = true;
    for (int i=1; i<n; i++){
        for (int target=1; target<=max_range; target++){
            bool notPick = dp[i-1][target];
            bool pick = false;
            if (target >= arr[i]) pick = dp[i-1][target-arr[i]];
            dp[i][target] = (notPick || pick);
        }
    }
    int result = INT_MAX;
    for (int i=0; i<=max_range; i++){
        int val = dp[n-1][i];
        if (val != 0){
            int diff = abs(total - 2*i);
            result = min(result, diff);
        }

    }
    return result;
}

//TC - O(N*M) + O(M);
//SC - O(N*M)

//You can space optimize it



