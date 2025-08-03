#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k) {
    long n = arr.size();
    long count = 0;
    for (long i=0; i<n; i++){
        long tempXor = 0;
        for (long j=i; j<n; j++){
            tempXor = tempXor ^ arr[j];
            if (tempXor == k){
                count++;
            }
        }
    }
    return count;
}

//Optimal Solution
long subarrayXor(vector<int> &arr, int k) {
    long n = arr.size();
    long count = 0;
    long tempXor = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for (long i=0; i<n; i++){
        tempXor ^= arr[i];
        long remaining = tempXor ^ k;
        if (mpp.find(remaining) != mpp.end()){
            count += mpp[remaining];
        }
        mpp[tempXor]++;
    }
    return count;
}
