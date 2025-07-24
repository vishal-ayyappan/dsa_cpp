#include <bits/stdc++.h> 
using namespace std;

//Matrix Chain Multiplication (Partition DP)

//Recursion

//f(i,j) --> minimum cost to multiply the all the matrix from i to j into one.
//ith matrix is given by arr[i-1]*arr[i], where i starts from 1.
int getMinCost(vector<int>& arr, int i, int j){
    //There will be no operations if there is just one matrix
    if (i == j) return 0;
    int mini = INT_MAX;
    //Do the Partitions
    for (int k=i; k<j; k++){
        int steps = getMinCost(arr, i, k) + getMinCost(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini, steps);
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N){
    return getMinCost(arr, 1, N-1);
}


//DP --> memoization
int getMinCostDP(vector<int> &arr, int i, int j, vector<vector<int>>& dp){
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    //Do the Partitions
    for (int k=i; k<j; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + getMinCostDP(arr, i, k, dp) + getMinCostDP(arr, k+1, j, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp (N, vector<int> (N, -1));
    //dp[i][j] --> min cost to multiply matrix i to j.
    return getMinCostDP(arr, 1, N-1, dp);
}

//DP --> Tabulation
int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp (N, vector<int> (N, -1));
    //dp[i][j] --> min cost to multiply matrix i to j.
    //Base Cases
    //When it is just one matrix, there are no operations involved.
    for (int i=1; i<N; i++) dp[i][i] = 0;
    for (int i=N-1; i>=1; i--){
        for (int j=i+1; j<N; j++){
            int mini = INT_MAX;
            for (int k=i; k<j; k++){
                //Partition into 2
                int steps = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}

