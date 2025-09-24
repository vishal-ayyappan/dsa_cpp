#include <bits/stdc++.h>
using namespace std;

//Top K Frequent Elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    //Naive way
    int n = nums.size();
    //Store the el and the freq in the map
    unordered_map<int, int> mpp;
    for (int i=0; i<n; i++) mpp[nums[i]]++;
    //Put (freq, value) in the priority queue
    priority_queue<pair<int, int>> pq; //Max Heap
    for (auto& it : mpp){
        int value = it.first;
        int freq = it.second;
        pq.push({freq, value});
    }
    vector<int> ans;
    while (k > 0){
        auto item = pq.top();
        pq.pop();
        int element = item.second;
        ans.push_back(element);
        k--;
    }
    return ans;
}

//Another way (Bucket sort)
vector<int> topKFrequent(vector<int>& nums, int k) {
    //Naive way
    int n = nums.size();
    //Store the el and the freq in the map
    unordered_map<int, int> mpp;
    for (int i=0; i<n; i++) mpp[nums[i]]++;
    vector<vector<int>> bucket (n+1);
    for (auto& it : mpp){
        int value = it.first;
        int freq = it.second;
        bucket[freq].push_back(value);
    }
    vector<int> ans;
    for (int i=n; i>=0; i--){
        for (int& el : bucket[i]){
            ans.push_back(el);
            k--;
            if (k == 0) return ans;
        }
    }
    return {};
}

