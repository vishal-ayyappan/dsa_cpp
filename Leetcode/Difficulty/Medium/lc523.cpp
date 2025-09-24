#include <bits/stdc++.h>
using namespace std;

//Continuous Subarray Sum

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2) return false;
    unordered_map<int, int> mpp;
    mpp[0] = -1;
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += nums[i];
        int rem = sum % k;
        if (mpp.find(rem) != mpp.end()){
            if (i - mpp[rem] > 1) return true;
        }
        else mpp[rem] = i;
    }
    return false;
}