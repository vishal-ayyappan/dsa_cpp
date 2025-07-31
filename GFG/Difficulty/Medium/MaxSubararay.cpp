#include <bits/stdc++.h>
using namespace std;

//Print Max Subarray Sum (Keep track of the ansStart and ansEnd)

vector<int> findSubarray(vector<int>& arr) {
    int n = arr.size();
    int maxSum = 0;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int i = 0;
    while (i < n){
        if (sum == 0) start = i;
        sum += arr[i];
        if (sum >= maxSum){
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
        i++;
    }
    vector<int> ans;
    for (int i=ansStart; i<=ansEnd; i++){
        ans.push_back(arr[i]);
    }
    return ans;
}


//Max Subarray (Only Positive values)
vector<int> findSubarray(vector<int>& arr) {
    int n = arr.size();
    int maxSum = 0;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int i = 0;
    while (i < n){
        if (sum == 0) start = i;
        if (arr[i] < 0){
            sum = 0;
            i++;
            continue;
        } 
        sum += arr[i];
        if (sum >= maxSum){
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        i++;
    }
    vector<int> ans;
    if (maxSum == 0) return {-1};
    for (int i=ansStart; i<=ansEnd; i++){
        ans.push_back(arr[i]);
    }
    return ans;
}