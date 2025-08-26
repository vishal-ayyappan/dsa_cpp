#include <bits/stdc++.h>
using namespace std;

//Diagonal Traversal

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    // Store elements in the map, according to the condition
    int m = mat.size();
    int n = mat[0].size();
    map<int, vector<int>> mpp;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            int idx = i + j;
            mpp[idx].push_back(mat[i][j]);
        }
    }
    vector<int> ans;
    for (auto& it : mpp){
        if (it.first % 2 == 0){
            reverse(it.second.begin(), it.second.end());
        }
        int size = it.second.size();
        for (int i=0; i<size; i++){
            ans.push_back(it.second[i]);
        }
    }
    return ans;
}