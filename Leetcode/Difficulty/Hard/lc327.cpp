#include <bits/stdc++.h>
using namespace std;

//Count of Range Sum (Tough Problem)

// 1/ Compute the prefix sum
// 2/ Do merge sort on that prefix sum

void mergeArray(vector<long long>& prefix, int start, int middle, int end){
    int i = start; 
    int j = middle;
    vector<long long> v;
    while (i < middle && j < end){
        if (prefix[i] <= prefix[j]){
            v.push_back(prefix[i]);
            i++;
        }
        else{
            v.push_back(prefix[j]);
            j++;
        }
    }
    while (i < middle){
        v.push_back(prefix[i]);
        i++;
    }
    while (j < end){
        v.push_back(prefix[j]);
        j++;
    }
    int idx = 0;
    for (int i=start; i<end; i++){
        prefix[i] = v[idx];
        idx++;
    }
}

int func(vector<long long>& prefix, int lower, int upper, int start, int middle, int end){
    int count = 0;
    int j = middle, k = middle;
    for (int i = start; i < middle; ++i) {
        // For each i, we want fresh j and k pointers
        while (k < end && (long long)prefix[k] - (long long)prefix[i] < (long long)lower) ++k;
        while (j < end && (long long)prefix[j] - (long long)prefix[i] <= (long long)upper) ++j;
        count += j - k;
    }
    return count;
}


int getCount(vector<long long>& prefix, int lower, int upper, int start, int end){
    if (end - start <= 1) return 0; //No pairs
    int middle = start + (end-start)/2;
    int count = 0;
    count += getCount(prefix, lower, upper, start, middle);
    count += getCount(prefix, lower, upper, middle, end);
    count += func(prefix, lower, upper, start, middle, end);
    mergeArray(prefix, start, middle, end);
    return count;
}

vector<long long> getPrefix(vector<int>& nums){
    int n = nums.size();
    vector<long long> prefix (n+1);
    prefix[0] = 0;
    for (int i=0; i<n; i++){
        prefix[i+1] = prefix[i] + (long long)nums[i];
    }
    return prefix;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long long> prefix = getPrefix(nums);
    // Intuition: We have to count the total values that satisfy prefix[j+1] - prefix[i] belonging to [lower, upper] for (i,j)
    int n = prefix.size();
    return getCount(prefix, lower, upper, 0, n);
}