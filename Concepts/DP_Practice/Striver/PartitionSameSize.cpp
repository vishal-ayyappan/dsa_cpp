#include <bits/stdc++.h>
using namespace std;

// Partition Array Into Two Arrays to Minimize Sum Difference

unordered_map<int, vector<int>> getCount(vector<int>& arr){
    unordered_map<int, vector<int>> mpp;
    //Stores the number of elements included and an array of sums
    //Get all the sum using bitmasking
    int n = arr.size();
    int size = 1<<n;
    for (int i=0; i<size; i++){
        int count = 0;
        int sum = 0;
        for (int j=0; j<n; j++){
            //If the bit is set, add the element
            //This is how you check if the bit is set or not
            if ((i>>j) & 1){
                sum += arr[j];
                count++;
            }
        }
        mpp[count].push_back(sum);
    }
    return mpp;
}

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int half = n/2;
    int total = accumulate(nums.begin(), nums.end(), 0);
    //Meet in the middle approach (Optimized from 2^n to 2^n/2)
    vector<int> nums1 (nums.begin(), nums.begin()+half);
    vector<int> nums2 (nums.begin()+half, nums.end());
    //Fill out the left and right map, based on count
    unordered_map<int, vector<int>> left = getCount(nums1);
    unordered_map<int, vector<int>> right = getCount(nums2);
    //Sort the right map, for logn search
    for (auto& it : right) sort(it.second.begin(), it.second.end());
    //Now check for each count.
    int abs_diff = INT_MAX;
    for (int size=0; size<=half; size++){
        if (left.find(size) == left.end() || right.find(half-size) == right.end()) continue;
        vector<int> leftArr = left[size];
        vector<int> rightArr = right[half-size];
        //Now go through the left map, that has 'count' as the key
        //For right count
        for (int& s1 : left[size]){
            // 2(s1 + s2) should be as close to total
            // To be equal s2 should be total/2 - s1;
            int tent_s2 = total/2 - s1;
            //Check if there exists
            int idx = lower_bound(rightArr.begin(), rightArr.end(), tent_s2) - rightArr.begin();
            if (idx == rightArr.size()) idx = idx - 1;
            int combined = s1 + rightArr[idx];
            int diff = abs(total - 2*combined);
            abs_diff = min(abs_diff, diff);
        }
    }
    return abs_diff;
}

