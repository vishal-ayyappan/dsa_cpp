#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    //You do not need Dijkstra.
    //Simple queue is enough instead of priority queue as the priority is the number of steps, which increases monotonically
    //So, I think a simple bfs is enough
    const int MOD = 1e5;
    if (start == 0 && end != 0) return -1;
    vector<bool> visited (MOD, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 0;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            int val = q.front();
            q.pop();
            if (val == end) return count;
            for (int& num : arr){
                int item = (val * num) % MOD;
                if (!visited[item]){
                    visited[item] = true;
                    q.push(item);
                }
            }
        }
        count++;
    }
    return -1;
}