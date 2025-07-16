#include <bits/stdc++.h>
using namespace std;

//Split array with the same average
void getSubsetsAvg(vector<int>& nums, unordered_map<int, vector<int>>& mpp){
    int n = nums.size();
    int total = 1<<n;
    for (int mask=0; mask<total; mask++){
        int sum = 0;
        int count = 0;
        for (int i=0; i<n; i++){
            if (mask & (1<<i)){
                sum += nums[i];
                count++;
            }
        }
        mpp[count].push_back(sum);
    }
}

bool splitArraySameAverage(vector<int>& nums) {
    //Generate all subsets average.
    int n = nums.size();
    if (n==1) return false;
    int total = accumulate(nums.begin(), nums.end(), 0);
    unordered_map<int, vector<int>> leftMap;
    unordered_map<int, vector<int>> rightMap;
    vector<int> left;
    left.assign(nums.begin(), nums.begin() + n/2);
    vector<int> right;
    right.assign(nums.begin()+n/2, nums.end());
    getSubsetsAvg(left, leftMap);
    getSubsetsAvg(right, rightMap);
    for (auto& it : rightMap){
        sort(it.second.begin(), it.second.end());
    }
    //Go through each count and check
    for (int k=1; k<n; k++){
        int requiredSum = total*k;
        if (requiredSum%n != 0) continue;
        //Required sum shoud be an integer
        int targetSum = requiredSum/n;
        int size = left.size();
        for (int i=1; i<= min(k,size); i++){
            int j = k-i;
            if (leftMap.find(i) == leftMap.end()) continue;
            if (rightMap.find(j) == rightMap.end()) continue;
            vector<int> leftSum = leftMap[i];
            vector<int> rightSum = rightMap[j];
            for (int s1 : leftSum){
                int s2 = targetSum - s1;
                if (binary_search(rightSum.begin(), rightSum.end(), s2)) return true;
            }
        }
    }
    return false;
}

//DP --> Memoization
// f(idx, size, target) tells if we have a subsequence of size 'size' in the range 0 to idx, with sum 'target'
int check(vector<int>& nums, int idx, int size, int target, map<tuple<int,int,int>, bool>& mpp){
    if (idx < 0) return false;
    if (size == 0){
        if (target == 0) return true;
        return false;
    }
    auto key = make_tuple(idx, size, target);
    if (mpp.find(key) != mpp.end()) return mpp[key];
    int notPick = check(nums, idx-1, size, target, mpp);
    int pick = false;
    if (target >= nums[idx]) pick = check(nums, idx-1, size-1, target-nums[idx], mpp);
    mpp[key] = (pick || notPick);
    return mpp[key];
}

bool splitArraySameAverage(vector<int>& nums) {
    //Generate all subsets average.
    int n = nums.size();
    if (n==1) return false;
    int total = accumulate(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end());
    //Create a DP map
    map<tuple<int,int,int>, bool> mpp;
    //Subset size
    for (int k=1; k<=n; k++){
        int value = total*k;
        int target = value/n;
        if (value%n != 0) continue;
        int minSum = accumulate(nums.begin(), nums.begin(), 0);
        int maxSum = accumulate(nums.end()-k, nums.end(), 0);
        if (target < minSum || target > maxSum) continue;
        if (check(nums, n-1, k, target, mpp)) return true;
    }
    return false;
}
