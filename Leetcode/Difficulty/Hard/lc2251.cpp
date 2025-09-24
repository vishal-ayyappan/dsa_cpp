#include <bits/stdc++.h>
using namespace std;

//Number of Flowers in Full Bloom

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    //Store all the flower bloom time in a map
    map<int, int> mpp;
    mpp[0] = 0;
    int n = flowers.size();
    for (int i=0; i<n; i++){
        int start = flowers[i][0];
        int end = flowers[i][1];
        mpp[start]++;
        mpp[end+1]--;
    }
    int sum = 0;
    map<int, int> bloomCount;
    for (auto& it : mpp){
        //Total flowers at that time
        int time = it.first;
        int value = it.second;
        sum += value;
        bloomCount[time] = sum;
    }
    int m = people.size();
    vector<int> ans (m);
    for (int i=0; i<m; i++){
        int time = people[i];
        //If the time is there in the map
        //Go to the nearest lower value, that is present
        auto it = bloomCount.lower_bound(time);
        int mp_time = it->first;
        int mp_value = it->second;
        if (mp_time == time) ans[i] = mp_value;
        else{
            it--;
            ans[i] = it->second;
        }  
    }
    return ans;
}