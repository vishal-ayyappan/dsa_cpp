#include <bits/stdc++.h>
using namespace std;

//Largest Divisible Subset (Write the lexicographically largest ones)

vector<int> largestSubset(vector<int>& arr) {
    int n = arr.size();
    //Find the longest subset that satifies the condition.
    vector<int> dp (n, 1);
    //to store the element that comes before
    vector<int> parent (n);
    for (int i=0; i<n; i++) parent[i] = i;
    sort(arr.rbegin(), arr.rend()); //Sort descending order
    int maxLen = 1;
    int idx = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[j] % arr[i] == 0){
                int length = 1 + dp[j];
                if (length > dp[i]){
                    dp[i] = length;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > maxLen){
            maxLen = dp[i];
            idx = i;
        }
    }
    //Backtrack to get the subset
    vector<int> ans;
    while (idx != parent[idx]){
        ans.push_back(arr[idx]);
        idx = parent[idx];
    }
    ans.push_back(arr[idx]);
    sort(ans.begin(), ans.end());
    return ans;
}