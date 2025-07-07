#include <bits/stdc++.h>
using namespace std;

/*
0/ Same approach as 3Sum
1/ Keep a hold of the sum that is closest to 2;
*/

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int closest = INT_MAX;
    int ans;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++){
        if (i>0 && nums[i] == nums[i-1]) continue;
        int firstVal = nums[i];
        int j = i+1;
        int k = n-1;
        while (j < k){
            int secondVal = nums[j];
            int thirdVal = nums[k];
            int sum = firstVal + secondVal + thirdVal;
            if (sum == target) return target;
            if (sum > target){
                int diff = sum - target;
                if (diff < closest){
                    closest = diff;
                    ans = sum;
                }
                k--;
            }
            else{
                int diff = target - sum;
                if (diff < closest){
                    closest = diff;
                    ans = sum;
                }
                j++;
            }
        }
    }
    return ans;
}

//TC - O(NlogN) + O(N*N)
//SC - O(1)