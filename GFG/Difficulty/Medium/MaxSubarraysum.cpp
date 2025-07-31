#include <bits/stdc++.h>
using namespace std;

//Kadane's Algorithm

int maxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int maxSum = 0;
    int sum = 0;
    int i = 0;
    //Check if the entire array is -ve
    bool checkNegative = true;
    for (int i=0; i<n; i++){
        if (arr[i] >= 0){
            checkNegative = false;
            break;
        }
    }
    if (checkNegative) return *max_element(arr.begin(), arr.end());
    while (i < n){
        sum += arr[i];
        if (sum < 0){
            sum = 0;
        }
        maxSum = max(maxSum, sum);
        i++;
    }
    return maxSum;
}