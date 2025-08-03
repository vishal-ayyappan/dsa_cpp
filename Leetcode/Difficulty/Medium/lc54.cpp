#include <bits/stdc++.h>
using namespace std;

//Spiral Matrix

// Good understanding of how to use forloops in matrix

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rowEnd = matrix.size()-1;
    int colEnd = matrix[0].size()-1;
    vector<int> ans;
    int rowStart = 0;
    int colStart = 0;
    while (rowStart <= rowEnd || colStart <= colEnd){
        //Right Traversal
        for (int i=colStart; i<=colEnd; i++){
            ans.push_back(matrix[rowStart][i]);
        }
        rowStart++;
        if (rowStart > rowEnd) break;
        //Bottom Traversal
        for (int i=rowStart; i<=rowEnd; i++){
            ans.push_back(matrix[i][colEnd]);
        }
        colEnd--;
        if (colStart > colEnd) break;
        //Left Traversal
        for (int i=colEnd; i>=colStart; i--){
            ans.push_back(matrix[rowEnd][i]);
        }
        rowEnd--;
        if (rowStart > rowEnd) break;
        //Top traversal
        for (int i=rowEnd; i>=rowStart; i--){
            ans.push_back(matrix[i][colStart]);
        }
        colStart++;
        if (colStart > colEnd) break;
    }
    return ans;
}