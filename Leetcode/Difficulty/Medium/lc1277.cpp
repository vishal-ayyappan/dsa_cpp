#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    //Check all.
    vector<vector<int>> dp (m, vector<int> (n, 0));
    //Base Case
    for (int i=0; i<m; i++) if (matrix[i][n-1] == 1) dp[i][n-1] = 1;
    for (int i=0; i<n; i++) if (matrix[m-1][i] == 1) dp[m-1][i] = 1;
    for (int i=m-2; i>=0; i--){
        for (int j=n-2; j>=0; j--){
            if (matrix[i][j] == 1){
                //Why min?? Think!!
                dp[i][j] = 1 + min({dp[i+1][j+1], dp[i][j+1], dp[i+1][j]});
            }
        }
    }
    int count = 0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            count += dp[i][j];
        }
    }
    return count;
}