#include <bits/stdc++.h>
using namespace std;

//Count Submatrices With All Ones

int numSubmat(vector<vector<int>>& mat) {
    //Intuition, flatten it like a 1D array
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    //You do it for each row
    for (int i=0; i<n; i++){
        vector<int> required (m);
        int val = 1;
        for (int j=i; j<n; j++){
            int count = 0;
            for (int col=0; col<m; col++){
                required[col] += mat[j][col];
                if (required[col] == val) {
                    count++;
                    ans += count;
                }
                else count = 0;
            }
            val++;
        }
    }
    return ans;
}

// TC - O(N^3)