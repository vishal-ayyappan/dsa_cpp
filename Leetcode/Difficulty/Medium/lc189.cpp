#include <bits/stdc++.h>
using namespace std;

//Rotate array (to the right)

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    int moveBy = k % n;
    reverse(nums.begin(), nums.begin() + n - moveBy);
    reverse(nums.begin() + n - moveBy, nums.end());
    reverse(nums.begin(), nums.end());
}

//TC - O(2N)
//SC - O(1)