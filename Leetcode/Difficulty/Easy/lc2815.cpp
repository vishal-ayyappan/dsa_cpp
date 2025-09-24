#include <bits/stdc++.h>
using namespace std;

//Max Pair Sum in an Array

class Solution {
private:
    int getLargestDigit(int num){
        int largest = 0;
        while (num != 0){
            int dig = num % 10;
            num = num / 10;
            largest = max(largest, dig);
        }
        return largest;
    }
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        //Have to get the largest digit for each number
        //map to store digit and the numbers associated with it.
        unordered_map<int, vector<int>> mpp;
        for (int i=0; i<n; i++){
            int largest = getLargestDigit(nums[i]);
            mpp[largest].push_back(nums[i]);
        }
        for (auto& it : mpp) sort(it.second.begin(), it.second.end());
        int ans = -1;
        for (auto& it : mpp){
            vector<int> comp = it.second;
            if (comp.size() > 1){
                int value = comp[comp.size()-1] + comp[comp.size()-2];
                ans = max(ans, value);
            }
        }
        return ans;
    }
};