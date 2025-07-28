#include <bits/stdc++.h>
using namespace std;

int countHillValley(vector<int>& nums) {
    int n = nums.size();
    vector<int> v;
    int count = 0;
    //Remove adjacent the duplicates
    v.push_back(nums[0]);
    for (int i=1; i<n; i++){
        if (nums[i] != nums[i-1]) v.push_back(nums[i]);
    }
    int j = 1;
    while (j < v.size()-1){
        //Its either a hill
        if (v[j] > v[j-1] && v[j] > v[j+1]) count++;
        //Its either a valley
        else if (v[j] < v[j-1] && v[j] < v[j+1]) count++;
        j++;
    }
    return count;
}