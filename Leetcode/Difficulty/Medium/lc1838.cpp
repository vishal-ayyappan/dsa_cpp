#include <bits/stdc++.h>
using namespace std;

//Frequency of the Most Frequent Element

int maxFrequency(vector<int>& nums, int k) {
    int n = nums.size();
    //You have to do a prefix sum + sliding window approach
    sort(nums.begin(), nums.end());
    long long sum = 0;
    int left = 0;
    int maxi = 0;
    for (int right=0; right<n; right++){
        sum += nums[right];
        while (left < n && 1LL*(right-left+1)*nums[right] > sum + k){
            sum -= nums[left];
            left++;
        }
        int size = right-left+1;
        maxi = max(maxi, size);
    }
    return maxi;
}