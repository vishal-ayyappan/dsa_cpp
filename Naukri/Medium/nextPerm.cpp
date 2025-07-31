#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    vector<int> ans = A;
    int n = A.size();
    int j = -1;
    for (int i=n-1; i>=1; i--){
        if (ans[i] > ans[i-1]){
            j = i-1;
            break;
        }
    }
    if (j == -1){
        sort(ans.begin(), ans.end());
        return ans;
    }
    //j is the index from which we have to change, the rest is unchanged
    int element = ans[j];
    int mini = ans[j+1];
    int maxIdx = j+1;
    for (int i=j+2; i<n; i++){
        //We have to find the minimum value, greater than element
        if (ans[i] <= element) continue;
        if (ans[i] < mini){
            mini = ans[i];
            maxIdx = i;
        }
    }
    swap(ans[j], ans[maxIdx]);
    //Sort the rest
    sort(ans.begin()+j+1, ans.end());
    return ans;
}