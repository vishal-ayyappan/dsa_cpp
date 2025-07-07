#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int count = 0;
    int idx = 0;
    for (int i=0; i<n; i++){
        if (nums[i] != val){
            nums[idx] = 0;
            count++;
            idx++;
        }
    }
    return count;
}