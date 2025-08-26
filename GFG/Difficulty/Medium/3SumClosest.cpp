#include <bits/stdc++.h>
using namespace std;

//3 Sum Closest

int closest3Sum(vector<int> &arr, int target) {
    int n = arr.size();
    int abs_diff = INT_MAX;
    int ans;
    // 0/ Sort the array
    sort(arr.begin(), arr.end());
    for (int i=0; i<n; i++){
        if (i != 0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while (j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == target) return sum;
            if (sum > target) {
                int diff = sum - target;
                if (diff < abs_diff){
                    abs_diff = diff;
                    ans = sum;
                }
                //Have to return the maximum sum
                else if (diff == abs_diff){
                    if (sum > ans) ans = sum;
                }
                k--;
            }
            else{
                int diff = target - sum;
                if (diff < abs_diff){
                    abs_diff = diff;
                    ans = sum;
                }
                else if (diff == abs_diff){
                    if (sum > ans) ans = sum;
                }
                j++;
            }
        }
    }
    return ans;
}