#include <bits/stdc++.h>
using namespace std;

//Proper BackTracking Problem

// Maximum Length of a Concatenated String with Unique Characters
bool isUnique(string& a, string& b){
    unordered_set<char> unique;
    int len2 = b.length();
    for (int i=0; i<len2; i++) {
        //If you find this in the set
        if (unique.find(b[i]) != unique.end()) return false;
        unique.insert(b[i]);
    }
    // If any character of string b in a, then it is not unique
    int len = a.length();
    //Push all the characters of a in the set
    unordered_set<char> s;
    for (int i=0; i<len; i++) s.insert(a[i]);
    //Now check if any character in b is in a
    for (int i=0; i<len2; i++){
        if (s.find(b[i]) != s.end()) return false;
    }
    return true;
}

int getLength(vector<string>& arr, int i, string s, unordered_map<string, int>& mpp){
    if (i >= arr.size()) return 0;
    if (mpp.find(s) != mpp.end()) return mpp[s];
    //You do not pick the sequence
    int notPick = getLength(arr, i+1, s, mpp);
    //You try to pick
    //Check if you can pick
    int pick = 0;
    if (isUnique(s, arr[i])) {
        s += arr[i];
        pick = arr[i].size() + getLength(arr, i+1, s, mpp);
    }
    mpp[s] = max(notPick, pick);
    return mpp[s];
}

int maxLength(vector<string>& arr) {
    int n = arr.size();
    string s;
    unordered_map<string, int> mpp;
    return getLength(arr, 0, s, mpp);
}