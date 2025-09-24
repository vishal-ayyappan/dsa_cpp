#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
    //Sort according to end time
    vector<pair<int, int>> sorted;
    int n = start.size();
    for (int i=0; i<n; i++){
        sorted.push_back({end[i], start[i]});
    }
    //Sort according to end time
    sort(sorted.begin(), sorted.end());
    int i = 0; 
    int freetime = -1;
    int count = 0;
    while (i<n){
        int startTime = sorted[i].second;
        int endTime = sorted[i].first;
        if (startTime > freetime){
            count++;
            freetime = endTime;
        }
        i++;
    }
    return count;
}