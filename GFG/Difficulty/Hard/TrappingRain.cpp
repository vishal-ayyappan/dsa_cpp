#include <bits/stdc++.h>
using namespace std;

vector<int> getPge(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> pge (n);
    pge[0] = arr[0];
    for (int i=1; i<n; i++){
        pge[i] = max(pge[i-1], arr[i]);
    }
    return pge;
}

vector<int> getNge(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nge (n);
    nge[n-1] = arr[n-1];
    for (int i=n-2; i>=0; i--){
        nge[i] = max(nge[i+1], arr[i]);
    }
    return nge;
}

int maxWater(vector<int> &arr) {
    vector<int> pge = getPge(arr);
    vector<int> nge = getNge(arr);
    int n = arr.size();
    int ans = 0;
    for (int i=0; i<n; i++){
        if (arr[i] < pge[i] && arr[i] < nge[i]){
            ans += min(pge[i], nge[i]) - arr[i];
        }
    }
    return ans;
}