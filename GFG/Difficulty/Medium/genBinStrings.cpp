#include <bits/stdc++.h>
using namespace std;

//Generate all binary strings

void getBinaryStrings(int num, string& ds, vector<string>& ans){
    if (ds.size() == num){
        ans.push_back(ds);
        return;
    }
    ds.push_back('0');
    getBinaryStrings(num, ds, ans);
    ds.pop_back();
    if (ds.empty() || ds.back() == '0'){
        //You add a 1
        ds.push_back('1');
        getBinaryStrings(num, ds, ans);
        ds.pop_back();
    }

}

vector<string> generateBinaryStrings(int num) {
    vector<string> ans;
    string ds;
    getBinaryStrings(num, ds, ans);
    return ans;
}