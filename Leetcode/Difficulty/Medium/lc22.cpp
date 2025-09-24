#include <bits/stdc++.h>
using namespace std;

//Generate Parentheses
void getStrings(int n, string& ds, vector<string>& ans, int total){
    if (total == -1) return;
    if (ds.length() == 2*n){
        if (total == 0) ans.push_back(ds);
        return;
    }
    //Push '('
    ds.push_back('(');
    total += 1;
    getStrings(n, ds, ans, total);
    ds.pop_back();
    total -= 1;
    //Push ')'
    ds.push_back(')');
    total -= 1;
    getStrings(n, ds, ans, total);
    ds.pop_back();
    total += 1;
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string ds;
    getStrings(n, ds, ans, 0);
    return ans;
}