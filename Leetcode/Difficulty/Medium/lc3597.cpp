#include <bits/stdc++.h>
using namespace std;

/*
Use a hashmap to check, whether they are already present. If not push it 
in the ans and put it in the map
*/

vector<string> partitionString(string s) {
    unordered_map<string, bool> mpp;
    vector<string> ans;
    int n = s.length();
    int i = 0;
    while (i < n){
        string res;
        res.push_back(s[i]);
        if (mpp.find(res) == mpp.end()){
            ans.push_back(res);
            mpp[res] = true;
            i++;
            continue;
        }
        while (i<n && mpp.find(res) != mpp.end()){
            i++;
            if (i<n) res += s[i];
        }
        if (i != n){
            ans.push_back(res);
            mpp[res] = true;
        }
        i++;
    }
    return ans;
}