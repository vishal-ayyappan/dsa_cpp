#include <bits/stdc++.h>
using namespace std;

//Subarray Sum Equals K

//Try to hash the sum of the subarrays starting from the first

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mpp;
    //If the sum is the target, then remaining will be 0, so that could be a subarray
    mpp[0] = 1;
    int sum = 0;
    int count = 0;
    for (int i=0; i<n; i++){
        sum += nums[i];
        int remaining = sum - k;
        if (mpp.find(remaining) != mpp.end()){
            count += mpp[remaining];
        }  
        mpp[sum]++; 
    }
    return count;
}