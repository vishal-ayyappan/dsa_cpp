#include <bits/stdc++.h>
using namespace std;

//Perfect Squares (Very Good Question) --> Similar to Dijkstras
int getMin(int n, int num, vector<vector<int>>& dp){
    if (num <= 0) return INT_MAX;
    if (n == 0) return 0;
    if (dp[n][num] != -1) return dp[n][num];
    //If you do not pick
    int notPick = getMin(n, num-1, dp);
    //If you pick
    int val = num*num;
    int pick = INT_MAX;
    if (n - val >= 0) {
        int res = getMin(n-val, num, dp);
        if (res != INT_MAX) pick = 1 + res;
    }
    return dp[n][num] = min(pick, notPick);
}

int numSquares(int n) {
    int num = sqrt(n);
    vector<vector<int>> dp (n, vector<int> (num+1, -1));
    //dp[i][j] --> min perfect square numbers needed to get to i, with the last number being j
    return getMin(n, num, dp);
}

//Another approach (Can be done using Dijkstras algo)
int numSquares(int n) {
    int num = sqrt(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n});
    vector<bool> visited (n+1, false);
    visited[n] = true;
    while (true){
        auto item = pq.top();
        pq.pop();
        int og_num = item.second;
        int add_count = item.first;
        if (og_num == 0) return add_count;
        for (int val=num; val>=1; val--){
            int rem = val*val;
            int new_num = og_num - rem;
            if (new_num >= 0 && !visited[new_num]) {
                visited[new_num] = true;
                pq.push({add_count+1, og_num-rem});
            }
        }
    }
    return -1;
}
