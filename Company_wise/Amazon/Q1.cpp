#include <bits/stdc++.h>
using namespace std;

int getMaxPlayers(vector<int>& booster_a, vector<int>& booster_b, vector<int>& booster_c){
    //Get the data structure
    vector<vector<int>> player;
    int n = booster_a.size();
    for (int i=0; i<n; i++){
        int val1 = booster_a[i];
        int val2 = booster_b[i];
        int val3 = booster_c[i];
        player.push_back({val1, val2, val3});
    }
    int secondMax = 0;
    int thirdMax = 0;
    //Sort it in descending order
    for (int i=0; i<n; i++) sort(player[i].rbegin(), player[i].rend());
    //Get the second and third Max
    for (int i=0; i<n; i++){
        vector<int> temp = player[i];
        secondMax = max(secondMax, temp[1]);
        thirdMax = max(thirdMax, temp[2]);
    }
    int count = 0;
    for (int i=0; i<n; i++){
        int val1 = player[i][0];
        int val2 = player[i][1];
        if (val1 >= secondMax && val2 >= thirdMax) count++;
    }
    return count;
}