#include <bits/stdc++.h>
using namespace std;

//Sorting the matrix, diagonally

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    //Keep a map of the indices and the values
    map<int, vector<pair<int, int>>> indices;
    map<int, vector<int>> values;
    //Denote all the points as nodes
    int n = mat.size();
    int m = mat[0].size();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //Flattening will not work
            //This is the core logic, this is how you group (i-j) will same for the diagonal elements
            int idx = i - j;
            //If it is a new diagonal
            indices[idx].push_back({i, j});
            values[idx].push_back(mat[i][j]);
        }
    }
    for (auto& it : values){
        sort(it.second.begin(), it.second.end());
    }
    vector<vector<int>> ans (n, vector<int> (m, 0));
    for (auto& it : indices){
        int idx = it.first;
        vector<int> sorted = values[idx];
        vector<pair<int, int>> new_indices = indices[idx];
        for (int i=0; i<sorted.size(); i++){
            int r = new_indices[i].first;
            int c = new_indices[i].second;
            ans[r][c] = sorted[i];
        }
    }
    return ans;
}

// TC --> O(N*N) + O(P*K*logK) + O(P*K)
