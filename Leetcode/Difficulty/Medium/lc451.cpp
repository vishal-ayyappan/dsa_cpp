#include <bits/stdc++.h>
using namespace std;

//Sort characters by frequency

string frequencySort(string s) {
    unordered_map<char, int> mpp;
    int n = s.length();
    //Store the character with its frequency
    for (int i=0; i<n; i++) mpp[s[i]]++;
    //Go through the map and sort it according to frequency
    priority_queue<pair<int, char>> pq;
    for (auto& it : mpp){
        char ch = it.first;
        int freq = it.second;
        pq.push({freq, ch});
    }
    string ans = "";
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        int freq = item.first;
        char ch = item.second;
        string p (freq, ch);
        ans += p;
    }
    return ans;
}