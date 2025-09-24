#include <bits/stdc++.h>
using namespace std;

//Longest Bitonic subsequence
int LongestBitonicSequence(int n, vector<int> &nums) {
    vector<int> dp1 (n, 1);
    // dp1[i] --> LISubseq from 0 to i
    vector<int> dp2 (n, 1);
    // dp2[i] --> LISubseq from i to n-1
    
    bool isAscending = true;
    for (int i=0; i<n-1; i++){
        if (nums[i] <= nums[i+1]) continue;
        else {
            isAscending = false;
            break;
        }
    }
    if (isAscending) return 0;
    
    bool isDescending = true;
    for (int i=0; i<n-1; i++){
        if (nums[i] >= nums[i+1]) continue;
        else {
            isDescending = false;
            break;
        }
    }
    if (isDescending) return 0;
    

    //For LIS from 0 to i
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (nums[i] > nums[j]){
                dp1[i] = max(dp1[i], 1+dp1[j]);
            }
        } 
    }
    

    //For LIS from n-1 to i;
    for (int i=n-1; i>=0; i--){
        for (int j=n-1; j>i; j--){
            if (nums[i] > nums[j]){
                dp2[i] = max(dp2[i], 1+dp2[j]);
            }
        }
    }

    int maxi = 0;
    //Iterate through the array, should not be strictly increasing
    for (int i=0; i<n-1; i++){
        if (dp1[i] > 1 && dp2[i] > 1){
            int a = dp1[i] + dp2[i] - 1;
            maxi = max(maxi, a);
        }

    }
    return maxi;
}