#include <bits/stdc++.h>
using namespace std;

//Search a 2D Matrix II

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    //Start from the top right
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    //If you visit the same nodes again, then it is not found
    int row = 0;
    int col = n-1;
    while (row < m && col >= 0){
        if (matrix[row][col] == target) return true;
        //Go left
        if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}