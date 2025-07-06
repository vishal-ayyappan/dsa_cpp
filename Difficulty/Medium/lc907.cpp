#include <bits/stdc++.h>
using namespace std;

//Sum of subarray minimum

//Compute the nse and pse of each element
//Find the number of subarrays where an element is the min value
//And multiply it with that element


vector<int> getPseIdx(vector<int>& arr){
    int n = arr.size();
    vector<int> ans (n);
    stack<int> st;
    for (int i=0; i<n; i++){
        if (st.empty()) ans[i] = -1;
        else{
            while (!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> getNseIdx(vector<int>& arr){
    int n = arr.size();
    vector<int> ans (n);
    stack<int> st;
    for (int i=n-1; i>=0; i--){
        if (st.empty()) ans[i] = n;
        else{
            while (!st.empty() && arr[i] < arr[st.top()]) st.pop();
            if (st.empty()) ans[i] = n;
            else ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> nseIdx = getNseIdx(arr);
    vector<int> pseIdx = getPseIdx(arr);
    long long ans = 0;
    long long mod = 1e9 + 7;
    for (int i=0; i<n; i++){
        int first = i - pseIdx[i];
        int second = nseIdx[i] - i;
        long long val = (long long)first*second;
        ans = (ans + val*arr[i])%mod;
    }
    return (int)ans;
}

//TC - O(N) + O(N) + O(N)
//SC - O(2N)