#include <bits/stdc++.h>
using namespace std;

//Understand the question first!!!

/*
0/ Traverse the array and get the max sequential prefix sum 
/1 Check if it is in the array
*/

int missingInteger(vector<int>& nums) {
    int n = nums.size();
    int maxPrefixSum = nums[0];
    int i = 0;
    int maxLength = 1;
    while (i < n){
        int length = 1;
        while (i<n-1 && nums[i+1] == nums[i] + 1){
            maxPrefixSum += nums[i+1];
            i++;
        }
        break;
    }
    set<int> st (nums.begin(), nums.end());
    for (auto it : st){
        if (it == maxPrefixSum) maxPrefixSum++;
        else if (it > maxPrefixSum) break;
    }
    return maxPrefixSum;
}

//TC - O(N) + O(NlogN)