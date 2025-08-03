#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int>& arr) {
    int n = arr.size();
    int target = 0;
    unordered_map<int, int> mpp;
    mpp[0] = -1;
    int maxLen = 0;
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
        int remaining = sum - target;
        if (mpp.find(remaining) != mpp.end()){
            int length = i - mpp[remaining];
            maxLen = max(maxLen, length);
        }
        //If the sum is already there, do not update the index as we require the longest subarray
        if (mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }
    return maxLen;
}