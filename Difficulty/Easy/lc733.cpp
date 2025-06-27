//Flood fill
#include <bits/stdc++.h>
using namespace std;

//Approach
/*
0/ If the original color is the same as color to be modified, return the same image
2/ Then do a bfs, and modify the image
*/

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int ogcolor = image[sr][sc];
    if (ogcolor == color) return image;
    queue<pair<int,int>> q;
    q.push({sr,sc});
    image[sr][sc] = color;
    vector<int> delRow {1,0,-1,0};
    vector<int> delColumn {0,1,0,-1};
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            int row = item.first;
            int column = item.second;
            for (int j=0; j<delRow.size(); j++){
                int nrow = row + delRow[j];
                int ncol = column + delColumn[j];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                image[nrow][ncol] == ogcolor){
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
    }
    return image;
}