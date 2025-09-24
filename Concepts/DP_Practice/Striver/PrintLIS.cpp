#include <bits/stdc++.h>
using namespace std;

//Printing LIS
vector<int> getLIS(vector<int>& arr) {
    //Get the LIS while simultanously updating the parent of each element
    int n = arr.size();
    vector<int> dp (n, 1);
    vector<int> parent (n);
    for (int i=0; i<n; i++) parent[i] = i;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[j] < arr[i]){
                int length = 1 + dp[j];
                if (length > dp[i]){
                    dp[i] = length;
                    parent[i] = j;
                }
            }
        }
    }
    //Now BackTrack to get the subsequence
    int startIdx = 0;
    int maxi = *max_element(dp.begin(), dp.end());
    for (int i=0; i<n; i++){
        if (dp[i] == maxi){
            startIdx = i;
            break;
        }
    }
    vector<int> ans;
    while (startIdx != parent[startIdx]){
        ans.push_back(arr[startIdx]);
        startIdx = parent[startIdx];
    }
    ans.push_back(arr[startIdx]);
    reverse(ans.begin(), ans.end());
    return ans;
}