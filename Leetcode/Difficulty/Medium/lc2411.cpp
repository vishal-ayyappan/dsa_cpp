#include <bits/stdc++.h>
using namespace std;

//Smallest Subarrays With Maximum Bitwise OR

vector<int> getMaxOR(vector<int>& nums){
    int n = nums.size();
    vector<int> ans (n);
    int target = 0;
    for (int i=n-1; i>=0; i--){
        target = target | nums[i];
        ans[i] = target;
    }
    return ans;
}

vector<int> smallestSubarrays(vector<int>& nums) {
    //Get the target
    vector<int> targetXor = getMaxOR(nums);
    int n = nums.size();
    vector<int> ans (n);
    //Cannot do DP because there is no overlapping subproblems
    for (int i=n-1; i>=0; i--){
        int temp = 0;
        int len = 0;
        int target = targetXor[i];
        for (int j=i; j<n; j++){
            temp = temp | nums[j];
            if (temp == target){
                len = j-i+1;
                break;
            }
        }
        ans[i] = len;
    }
    return ans;
}

//TC - O(N^2)
//SC - O(N)


//Optimal Solution

vector<int> smallestSubarrays(vector<int>& nums) {
    //Get the target
    int n = nums.size();
    vector<int> setBitIdx (32, -1); 
    //setBitIdx[i] = j, it means that ith bit can be set by the element at index j in nums.
    vector<int> ans (n);
    for (int i=n-1; i>=0; i--){
        for (int bit=0; bit<31; bit++){
            //Check if bit is set or not
            if (nums[i]>>bit & 1){
                setBitIdx[bit] = i;
            }
        }
        int maxLen = i;
        for (int bit=0; bit<31; bit++){
            if (setBitIdx[bit] != -1){
                maxLen = max(maxLen, setBitIdx[bit]);
            }
        }
        ans[i] = maxLen - i + 1;
    }
    return ans;
}

//TC - O(32*N)
//SC - O(32)