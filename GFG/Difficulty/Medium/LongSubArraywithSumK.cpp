#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    //Use a hash map to store the values
    int n = arr.size();
    unordered_map<int, int> mpp;
    int sum = 0;
    int maxLen = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
        //Check if the reamining exists
        if (sum == k){
            maxLen = max(maxLen, i+1);
        }
        int remaining = sum - k;
        if (mpp.find(remaining) != mpp.end()){
            int idx = mpp[remaining];
            int length = i - idx;
            maxLen = max(maxLen, length);
        }
        //If the sum already exists, do not reupdate as we require the longest not the shortest
        if (mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }
    return maxLen;
}

//If the array only contains positive values, then use sliding window as the sum always increases