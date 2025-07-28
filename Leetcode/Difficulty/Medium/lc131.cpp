#include <bits/stdc++.h>
using namespace std;

//Palindrome Partitioning I

bool isPalindrome(string& s, int i, int j){
    if (i >= j) return true;
    if (s[i] == s[j]){
        return isPalindrome(s, i+1, j-1);
    }
    return false;
}

void getPartition(string& s, int idx, vector<string>& ds, vector<vector<string>>& ans){
    if (idx == s.size()){
        ans.push_back(ds);
        return;
    }
    string temp;
    for (int k=idx; k<s.length(); k++){
        temp.push_back(s[k]);
        if (isPalindrome(s, idx, k)){
            ds.push_back(temp);
            getPartition(s, k+1, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> ds;
    getPartition(s, 0, ds, ans);
    return ans;
}