#include <bits/stdc++.h>
using namespace std;

//Single-Threaded CPU

vector<int> getOrder(vector<vector<int>>& tasks) {
    //Store the tasks along with the index
    int n = tasks.size();
    vector<vector<int>> logs;
    for (int i=0; i<n; i++){
        int enqueue = tasks[i][0];
        int processing = tasks[i][1];
        logs.push_back({enqueue, processing, i});
    }
    //Sort according to enqueue time
    sort(logs.begin(), logs.end());
    //In the priority queue, store the processing time and the index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //Min heap
    //Get the result
    vector<int> ans;
    int i = 0;
    long long currTime = 0;
    while (i < n || !pq.empty()){
        //If the cpu is idle and no process is left in the stack
        if (pq.empty() && logs[i][0] >= currTime){
            currTime = logs[i][0];
        }
        //Push the elements, that are <= currTime
        while (i < n && logs[i][0] <= currTime){
            int processTime = logs[i][1];
            int idx = logs[i][2];
            pq.push({processTime, idx});
            i++;
        }
        auto item = pq.top();
        pq.pop();
        int processTime = item.first;
        int index = item.second;
        currTime += processTime;
        ans.push_back(index); 
    }
    return ans;
}