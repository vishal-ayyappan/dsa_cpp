#include <bits/stdc++.h>
using namespace std;

//Minimum Cost to Cut a Stick

int getMinCost(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
    //As it is sorted
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for (int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + getMinCost(cuts, i, k-1, dp) + getMinCost(cuts, k+1, j, dp);
        mini = min(cost, mini);
    }
    return dp[i][j] = mini;
}

int minCost(int n, vector<int>& cuts) {
    //Do the partition DP on cuts
    int size = cuts.size();
    //Sort the cuts, so that the cuts do not overlap
    sort(cuts.begin(), cuts.end());
    //Insert the first and last
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    //Create a DP array
    vector<vector<int>> dp (size+2, (vector<int> (size+2, -1)));
    return getMinCost(cuts, 1, size, dp);
}