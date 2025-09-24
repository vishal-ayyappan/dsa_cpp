#include <bits/stdc++.h>
using namespace std;

//Find Original Array From Doubled Array (Nice Question!!)
vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    vector<int> ans;
    if (n%2 == 1) return ans;
    //The number of elements in the doubled array should be strictly even
    //Store the val, freq
    map<int, int> mpp;
    for (int i=0; i<n; i++) mpp[changed[i]]++;
    //Now go through the map
    for (auto& it : mpp){
        int element = it.first;
        int freq = it.second;
        if (freq == 0) continue;
        if (element == 0){
            if (mpp[element] % 2 == 0){
                int zeros = mpp[element]/2;
                for (int i=0; i<zeros; i++) ans.push_back(element);
            }
        }
        else if (mpp.find(2*element) != mpp.end()){
            int nos = mpp[element];
            for (int i=0; i<nos; i++) {
                mpp[2*element]--;
                mpp[element]--;
                ans.push_back(element);
                if (mpp[2*element] == 0) break;
            }               
        }
    }
    if (ans.size() != n/2) return {};
    return ans;
}