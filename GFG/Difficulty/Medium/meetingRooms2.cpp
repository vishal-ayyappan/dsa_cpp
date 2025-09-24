#include <bits/stdc++.h>
using namespace std;

//Meeting Rooms 2
int minMeetingRooms(vector<int> &start, vector<int> &end) {
    //Find the min no of rooms required to accomodate all the meetings
    map<int, int> mpp;
    int n = start.size();
    for (int i=0; i<n; i++){
        mpp[start[i]]++;
        mpp[end[i]]--;
    }
    int sum = 0;
    int maxi = 0;
    for (auto& it : mpp){
        sum += it.second;
        maxi = max(maxi, sum);
    }
    return maxi;
}