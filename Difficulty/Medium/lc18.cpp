#include <bits/stdc++.h>
using namespace std;

/*
0/ Sort the array and do the rest
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i=0; i<n-3; i++){
        if (i>0 && nums[i] == nums[i-1]) continue;
        long long firstVal = nums[i];
        for (int j=i+1; j<n-2; j++){
            if (j>i+1 && nums[j] == nums[j-1]) continue;
            long long secondVal = nums[j];
            int k = j+1;
            int l = n-1;
            while (k < l){
                long long thirdVal = nums[k];
                long long fourthVal = nums[l];
                long long sum = firstVal + secondVal + thirdVal + fourthVal;
                if (sum == (long long)target){
                    vector<int> v {(int)firstVal, (int)secondVal, (int)thirdVal, (int)fourthVal};
                    if (ans.size() == 0 || ans.back() != v){
                        ans.push_back(v);
                    }
                    k++;
                    l--;
                }
                else if (sum > target) l--;
                else k++;
            }
        }
    }
    return ans;
}

//TC - O(N*N) + O(NlogN)
//SC - O(1)