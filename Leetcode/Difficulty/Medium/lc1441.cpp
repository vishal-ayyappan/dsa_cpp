#include <bits/stdc++.h>
using namespace std;

//Build an array using stack operations

vector<string> buildArray(vector<int>& target, int n) {
    int m = target.size();
    vector<int> newArray;
    vector<string> ans;
    int i = 1;
    while (i <= n){
        //Check if the current newArray equals target till that idx, pop until that happens
        int j = newArray.size() - 1;
        while (newArray.size() != 0 && newArray.back() != target[j]){
            newArray.pop_back();
            ans.push_back("Pop");
            j--;
        }
        //Push the new element
        newArray.push_back(i);
        ans.push_back("Push");
        i++;
        //Checking condition (if newArray is same as target, then we can break out)
        if (newArray.size() == m){
            bool isSame = true;
            for (int k=m-1; k>=0; k--){
                if (newArray[k] != target[k]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) break;
        }
    }
    return ans;
}

//Easier way

vector<string> buildArray(vector<int>& target, int n) {
    int m = target.size();
    vector<string> ans;
    int i = 1;
    int j = 0;
    while (j < m && i <= n){
        ans.push_back("Push");
        if (i == target[j]) j++;
        else ans.push_back("Pop");
        i++;
    }
    return ans;
}
