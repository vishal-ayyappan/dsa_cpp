#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> positive;
    vector<int> negative;
    for (int i=0; i<n; i++){
        if (nums[i] >= 0) positive.push_back(nums[i]);
        else negative.push_back(nums[i]);
    }
    int size = n/2;
    vector<int> ans;
    for (int i=0; i<size; i++){
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }
    return ans;
}

//Or (Optimal)

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans (n);
    int posidx = 0;
    int negIdx = 1;
    for (int i=0; i<n; i++){
        if (nums[i] >= 0){
            ans[posidx] = nums[i];
            posidx += 2;
        }
        else {
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
    }
    return ans;
}

