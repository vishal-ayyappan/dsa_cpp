#include <bits/stdc++.h>
using namespace std;

/*
0/ Sort the array
1/ While iterating keep 2 pointers, one at the end and other at i+1 (3 pointers)
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++){
        int j = i+1;
        int k = n-1;
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int target = nums[i];
        while (j < k){
            int num1 = nums[j];
            int num2 = nums[k];
            int sum = num1+num2;
            if (sum == -target) {
                vector<int> v {target, num1, num2};
                if (v != ans.back()){
                    ans.push_back(v);
                }
                j++;
                k--;
            }
            else if (sum > -target) k--;
            else j++;
        }
    }
    return ans;
}

//TC - O(NlogN) + O(N*N)
//SC - O(1) -> Extra space