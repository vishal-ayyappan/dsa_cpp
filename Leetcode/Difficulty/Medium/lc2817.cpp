#include <bits/stdc++.h>
using namespace std;

//Minimum Absolute Difference Between Elements With Constraint

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        multiset<int> ms;
        int right = n-1;
        int left = n - 1 - x;
        int mini = INT_MAX;
        //On the left side
        while (left >= 0){
            ms.insert(nums[right]);
            //Find the upper bound in the set
            auto it = ms.lower_bound(nums[left]);
            if (it == ms.end()) it--;
            int value = *it;
            int dist = abs(nums[left] - value);
            mini = min(mini, dist);
            right--;
            left--;
        }
        //On the right side
        left = 0;
        right = x;
        ms.clear();
        while (right < n){
            ms.insert(nums[left]);
            auto it = ms.lower_bound(nums[right]);
            //If the lower bound is not present
            if (it == ms.end()) it--;
            int value = *it;
            int dist = abs(nums[right]-value);
            mini = min(mini, dist);
            right++;
            left++;
        }
        return mini;
    }
};