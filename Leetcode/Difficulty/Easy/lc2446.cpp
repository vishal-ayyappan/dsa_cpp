#include <bits/stdc++.h>
using namespace std;

//Determine if Two Events Have Conflict

bool haveConflict(vector<string>& event1, vector<string>& event2) {
    vector<int> event1_num (2);
    vector<int> event2_num (2);
    for (int i=0; i<2; i++){
        int num1 = 0;
        int num2 = 0;
        for (int j=0; j<=1; j++){
            num1 = num1*10 + int(event1[i][j]);
            num2 = num2*10 + int(event2[i][j]);
        }
        num1 = num1*60;
        num2 = num2*60;
        int min1 = 0;
        int min2 = 0;
        for (int j=3; j<5; j++){
            min1 = min1*10 + int(event1[i][j]);
            min2 = min2*10 + int(event2[i][j]);
        } 
        num1 += min1;
        num2 += min2;
        event1_num[i] = num1;
        event2_num[i] = num2;
    }
    map<int,int> mpp;
    int from1 = event1_num[0];
    int to1 = event1_num[1];
    mpp[from1]++;
    mpp[to1 + 1]--;
    int from2 = event2_num[0];
    int to2 = event2_num[1];
    mpp[from2]++;
    mpp[to2 + 1]--;
    int sum = 0;
    for (auto& it : mpp){
        sum += it.second;
        if (sum > 1) return true;
    }
    return false;
}