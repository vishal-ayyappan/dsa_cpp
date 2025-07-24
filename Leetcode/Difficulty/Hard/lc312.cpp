#include <bits/stdc++.h>
using namespace std;

//Burst Balloons (You go from last burst to first burst) because the vice versa have dependable sub problems
int getMaxCoins(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
    //Base Case
    if (i > j) return 0;
    if (i == j) return dp[i][j] = nums[i-1]*nums[i]*nums[i+1];
    if (dp[i][j] != -1) return dp[i][j];
    int maxi = 0;
    for (int k=i; k<=j; k++){
        int cost = nums[i-1]*nums[k]*nums[j+1] + getMaxCoins(nums, i, k-1, dp) + getMaxCoins(nums, k+1, j, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp (n+2, vector<int> (n+2, -1));
    //dp[i][j] --> max coins you can get from i to j
    getMaxCoins(nums, 1, n, dp);
    return dp[1][n];
}


//DP --> Tabulation
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp (n+2, vector<int> (n+2, 0));
    //dp[i][j] --> max coins you can get from i to j
    for (int i=n; i>=1; i--){
        for (int j=1; j<=n; j++){
            if (i > j) continue;
            int maxi = INT_MIN;
            for (int k=i; k<=j; k++){
                int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}
