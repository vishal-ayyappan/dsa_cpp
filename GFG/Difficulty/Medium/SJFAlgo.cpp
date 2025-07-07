#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    int n = bt.size();
    sort(bt.begin(), bt.end());
    int time = 0;
    int waitTime = 0;
    for (int i=0; i<n; i++){
        waitTime += time;
        time += bt[i];
    }
    long long ans = waitTime/n;
    return ans;
}

//TC - O(NlogN) + O(N)
//SC - O(1)