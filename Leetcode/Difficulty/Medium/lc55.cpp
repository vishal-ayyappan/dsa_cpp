#include <bits/stdc++.h>
using namespace std;

//Jump Game

//Check if you can reach the last index
//Keep a track of the maximum Index that can be reached

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxi = 0;
    for (int i=0; i<n; i++){
        if (i > maxi) return false;
        maxi = max(maxi, i+nums[i]);
        if (maxi >= n-1) return true;
    }
    return false;
}

//TC ~ O(N)
//SC - O(1)