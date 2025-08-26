#include <bits/stdc++.h>
using namespace std;

//Car Pooling

bool carPooling(vector<vector<int>>& trips, int capacity) {
    //Create a map, that will store the numPassengers at each time interval (Can use an array as well, but it depends
    // on the input constraints, if it the times exceed 10^5, then, it is too much space)
    int n = trips.size();
    //Ordered map to store the time. (It should be sorted)
    map<int, int> mpp;
    for (int i=0; i<n; i++){
        int passengers = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];
        mpp[from] += passengers;
        mpp[to] -= passengers;
    }
    //Check if it exceeds capacity
    int sum = 0;
    for (auto& it : mpp){
        sum += it.second;
        //Check for capacity
        if (sum > capacity) return false;
    }
    return true;
}