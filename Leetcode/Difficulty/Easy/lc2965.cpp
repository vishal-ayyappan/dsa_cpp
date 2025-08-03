#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size()*grid.size();
    long long sum = (1LL * n * (n+1))/2;
    long long sumSquares = (1LL * n * (n+1) * (2*n + 1))/6;
    long long tempSum = 0;
    long long tempSumSquare = 0;
    for (int i=0; i<grid.size(); i++){
        for (int j=0; j<grid.size(); j++){
            tempSum += 1LL * grid[i][j];
            tempSumSquare += 1LL * grid[i][j] * grid[i][j];
        }
    }
    int value1 = sum - tempSum;
    int value2 = sumSquares - tempSumSquare;
    int value3 = value2/value1;
    // y - x is value 1
    // y + x is value 2
    int missing = (value1 + value3)/2;
    int repeating = (value3 - value1)/2;
    return {repeating, missing};
}