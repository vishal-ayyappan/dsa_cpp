#include <bits/stdc++.h>
using namespace std;

//Recursive Code
int getMaxVal(vector<int> weight, vector<int> value, int idx, int maxWeight){
    if (idx == 0){
        if (weight[idx] <= maxWeight) return value[idx];
        return 0;
    }
    int notPick = getMaxVal(weight, value, idx-1, maxWeight);
    int pick = INT_MIN;
    if (maxWeight >= weight[idx]) pick = value[idx] + getMaxVal(weight, value, idx-1, maxWeight-weight[idx]);
    return max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	//Express the func in terms of idx 
    //f(idx, maxWeight) -> maximum value in the range 0 to idx, where sum of weights < maxWeight
    return getMaxVal(weight, value, n-1, maxWeight);
}

//DP --> Memoization
int getMaxValDP(vector<int> weight, vector<int> value, int idx, int maxWeight, vector<vector<int>>& dp ){
    if (idx == 0){
        if (weight[idx] <= maxWeight) return value[idx];
        return 0;
    }
    if (dp[idx][maxWeight] != -1) return dp[idx][maxWeight];
    int notPick = getMaxValDP(weight, value, idx-1, maxWeight, dp);
    int pick = INT_MIN;
    if (maxWeight >= weight[idx]) pick = value[idx] + getMaxValDP(weight, value, idx-1, maxWeight-weight[idx], dp);
    dp[idx][maxWeight] =  max(pick, notPick);
    return dp[idx][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    if (n == 1 && maxWeight >= weight[0]) return value[0];
    if (n == 1) return 0;
	//Express the func in terms of idx 
    //f(idx, maxWeight) -> maximum value in the range 0 to idx, where sum of weights < maxWeight
    vector<vector<int>> dp (n, vector<int> (maxWeight+1, -1));
    getMaxValDP(weight, value, n-1, maxWeight, dp);
    return dp[n-1][maxWeight];
}

//DP --> Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    if (n == 1 && maxWeight >= weight[0]) return value[0];
    if (n == 1) return 0;
	//Express the func in terms of idx 
    //dp[idx][maxWeight] -> maximum value in the range 0 to idx, where sum of weights < maxWeight
    vector<vector<int>> dp (n, vector<int> (maxWeight+1, 0));
    //Write the Base Cases
    for (int i=0; i<=maxWeight; i++){
        if (weight[0] <= i) dp[0][i] = value[0];
    }
    for (int i=1; i<n; i++){
        for (int j=0; j<=maxWeight; j++){
            int notPick = dp[i-1][j];
            int pick = INT_MIN;
            if (j >= weight[i]) pick = value[i] + dp[i-1][j-weight[i]];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n-1][maxWeight];
}

//Extra Space Optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    if (n == 1 && maxWeight >= weight[0]) return value[0];
    if (n == 1) return 0;
    vector<int> prev (maxWeight+1, 0);
    //Write the Base Cases
    for (int i=0; i<=maxWeight; i++){
        if (weight[0] <= i) prev[i] = value[0];
    }
    for (int i=1; i<n; i++){
        for (int j=maxWeight; j>=0; j--){
            int notPick = prev[j];
            int pick = INT_MIN;
            if (j >= weight[i]) pick = value[i] + prev[j-weight[i]];
            prev[j] = max(pick, notPick);
        }
    }
    return prev[maxWeight];
}
