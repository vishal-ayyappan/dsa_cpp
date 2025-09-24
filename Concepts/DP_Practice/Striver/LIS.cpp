#include <bits/stdc++.h>
using namespace std;

//Longest Increasing Subsequence
int getLIS(vector<int>& arr, int current, int parent, vector<vector<int>>& dp){
    //Base Case
    if (current == arr.size()+1) return 0;
    if (dp[current][parent] != -1) return dp[current][parent];
    //You either notPick
    int notPick = getLIS(arr, current+1, parent, dp);
    //You either pick
    int pick = 0;
    if (parent == 0 || arr[current-1] > arr[parent-1]) pick = 1 + getLIS(arr, current+1, current, dp);
    dp[current][parent] = max(pick, notPick);
    return dp[current][parent];
}

int lis(vector<int>& arr) {
    //You have to keep store of the previous (in order to know which is longest)
    int n = arr.size();
    vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
    // dp[i][j] --> lis from i-1 to n-1 given prevElement is arr[j-1]
    getLIS(arr, 1, 0, dp);
    return dp[1][0];
}

//DP --> Tabulation
int lis(vector<int>& arr) {
    //You have to keep store of the previous (in order to know which is longest)
    int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (n+1, 0));
    // dp[i][j] --> lis from i-1 to n-1 given prevElement is arr[j-1]
    for (int idx=n-1; idx>=0; idx--){
        for (int prev_idx=idx-1; prev_idx>=-1; prev_idx--){
            int len = dp[idx+1][prev_idx+1];
            if (prev_idx == -1 || arr[idx] > arr[prev_idx]){
                len = max(len, 1+dp[idx+1][idx+1]);
            }
            dp[idx][prev_idx + 1]  = len;
        }
    }
    return dp[0][-1+1];
}

//Finding LIS using Tabulation (1D)
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp (n, 1);
    //dp[i] --> LIS subsequence ending at i
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

//LIS using binary search
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp (n, 1);
    //dp[i] --> LIS subsequence ending at i
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i=1; i<n; i++){
        int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
        if (idx == ans.size()) ans.push_back(arr[i]);
        else{
            ans[idx] = arr[i];
        }
    }
    return ans.size();
}


