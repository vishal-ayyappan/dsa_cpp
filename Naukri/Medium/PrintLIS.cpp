#include <bits/stdc++.h>
using namespace std;

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	//Get the dp table filled up
    vector<int> dp (n, 1);
    vector<int> hash (n);
    //You keep a hash Array
    //dp[i] --> LIS in the range (0 to i)
    int maxi = 1;
    int lastIndex = 0;
    for (int i=0; i<n; i++){
        hash[i] = i;
        for (int j=0; j<i; j++){
            if (arr[i] > arr[j]){
                int value = 1 + dp[j];
                dp[i] = max(dp[i], value);
                if (dp[i] == value){
                    hash[i] = j;
                }
            }
        }
        if (dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    //BackTracking
    vector<int> ans;
    while (hash[lastIndex] != lastIndex){
        ans.push_back(arr[lastIndex]);
        lastIndex = hash[lastIndex];
    }
    ans.push_back(arr[lastIndex]);
    reverse(ans.begin(), ans.end());
    return ans;
}
