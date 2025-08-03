#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<bool> rows (n, false);
    vector<bool> columns (m, false);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mat[i][j] == 0){
                rows[i] = true;
                columns[j] = true;
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (rows[i] || columns[j]) mat[i][j] = 0;
        }
    }
}