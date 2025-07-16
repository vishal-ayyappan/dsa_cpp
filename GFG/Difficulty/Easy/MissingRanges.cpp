#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
    int n = arr.size();
    vector<vector<int>> ans;
    //For each interval, both start and end should exist
    int start = lower;
    for (int i=0; i<n; i++){
        int value = arr[i];
        if (value > start){
            int end = value-1;
            int addEnd = min(end, upper);
            ans.push_back({start, addEnd});
            if (addEnd == upper) return ans;
        }
        start = value+1;
    }
    if (start <= upper) ans.push_back({start, upper});
    return ans;
}   

//(Variant) Missing Ranges with Dashes
vector<string> missingRangesVariant(vector<int> &arr, int lower, int upper) {
    int n = arr.size();
    vector<string> ans;
    //For each interval, both start and end should exist
    int start = lower;
    for (int i=0; i<n; i++){
        int end = min(upper, arr[i]-1);
        if (arr[i] - start > 2) ans.push_back(to_string(start) + '-' + to_string(end));
        else if (arr[i] - start == 2){
            ans.push_back(to_string(start));
            ans.push_back(to_string(start+1));
        }
        else ans.push_back(to_string(start));
        if (end == upper) return ans;
        start = arr[i] + 1;
    }
    if (upper - start == 0) ans.push_back(to_string(start));
    else if(upper - start == 1){
        ans.push_back(to_string(start));
        ans.push_back(to_string(start+1));
    }
    else ans.push_back(to_string(start) + '-' + to_string(upper));
    return ans; 
}   
