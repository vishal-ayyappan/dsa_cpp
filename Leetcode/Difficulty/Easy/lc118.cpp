#include <bits/stdc++.h>
using namespace std;

//Pascal's Triangle

vector<int> getRow(int n){
    vector<int> ans;
    ans.push_back(1);
    int fact = 1;
    for (int i=1; i<=n; i++){
        fact *= (n-i+1);
        fact /= i;
        ans.push_back(fact);
    }
    return ans;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i<numRows; i++){
        ans.push_back(getRow(i));
    }
    return ans;
}