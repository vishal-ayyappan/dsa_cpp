#include <bits/stdc++.h>
using namespace std;

//Most Profit Assigning Work

int findIdx(vector<vector<int>>& logs, int difficulty){
    //We do a binary search
    int n = logs.size();
    int start = 0;
    int end = n-1;
    //We find the upper bound
    while (start <= end){
        int middle = start + (end-start)/2;
        if (logs[middle][0] > difficulty) end = middle - 1;
        else start = middle + 1;
    }
    return start-1;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    //Sorting + Binary Search
    int n = difficulty.size();
    // 0/ Store the difficulty and profit in a container and sort it based on difficulty
    vector<vector<int>> logs (n, vector<int> (2));
    for (int i=0; i<n; i++){
        int diff = difficulty[i];
        int prof = profit[i];
        logs[i][0] = diff;
        logs[i][1] = prof;
    }
    sort(logs.begin(), logs.end());
    //Compute the prefix max of the profit
    vector<int> profitMax (n);
    profitMax[0] = logs[0][1];
    for (int i=1; i<n; i++){
        profitMax[i] = max(profitMax[i-1], logs[i][1]);
    }
    //Now get the max for each worker
    int ans = 0;
    int p = worker.size();
    for (int i=0; i<p; i++){
        int difficulty = worker[i];
        //Find the work that he can do
        int idx = findIdx(logs, difficulty);
        if (idx == -1) ans += 0;
        else ans += profitMax[idx];
    }
    return ans;
}