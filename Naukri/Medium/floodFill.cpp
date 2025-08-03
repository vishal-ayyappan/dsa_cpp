#include <bits/stdc++.h>
using namespace std;

void paintChanges(vector<vector<int>> &image, int color, int x, int y, vector<vector<bool>>& visited){
    int n = image.size();
    int m = image[0].size();
    //Do a BFS
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int j=0; j<4; j++){
            int nrow = row + delRow[j];
            int ncol = col + delCol[j];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                image[nrow][ncol] == color && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    int color = image[x][y];
    //Do a BFS or a DFS and whenever you encounter 'color', convert it into p
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    vector<vector<int>> newImg = image;
    //When traversing, only when you get the color and if is visited, you change the color to p
    paintChanges(image, color, x, y, visited);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (newImg[i][j] == color && visited[i][j]){
                newImg[i][j] = p;
            }
        }
    }
    return newImg;
}