#include <bits/stdc++.h>
using namespace std;

//Maximum Product Subarray

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    // It is either the max of subarray ending with i or the subarray starting with i;
    int pref = 1;
    int suff = 1;
    int maxVal = INT_MIN;
    for (int i=0; i<n; i++){
        pref *= nums[i];
        suff *= nums[n-i-1];
        maxVal = max(maxVal, max(pref, suff));
        if (pref == 0) pref = 1;
        if (suff == 0) suff = 1;
    }
    return maxVal;
}
