#include <bits/stdc++.h>
using namespace std;

// Counting Sort

vector<int> sort(int n, vector<int> &arr){
    int maxi = *max_element(arr.begin(), arr.end());
    int mini = *min_element(arr.begin(), arr.end());
    int range = maxi - mini;
    vector<int> count (range+1, 0);
    for (int i=0; i<n; i++){
        int offset = arr[i] - mini;
        count[offset]++;
    }
    //Now calculate the index where each belongs (Prefix sum of counts)
    int sum = 0;
    for (int i=0; i<count.size(); i++){
        sum += count[i];
        count[i] = sum;
    }
    //Go from the and place the elements (we iterate from the end for stability)
    vector<int> ans (n);
    for (int i=n-1; i>=0; i--){
        int value = arr[i] - mini;
        int idx = count[value] - 1;
        count[value]--;
        ans[idx] = arr[i];
    }
    return ans;
}