//Flood fill
#include <bits/stdc++.h>
using namespace std;

//Approach (Using BFS)
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

//TC - O(M*N*4);
//SC - O(M*N)


//Approach 2 (Using DFS)
void dfsTraversal(vector<vector<int>>& img, int row, int column, int color, int ogcolor,
vector<int> delRow, vector<int> delColumn){
    img[row][column] = color;
    for (int i=0; i<delRow.size(); i++){
        int nrow = row + delRow[i];
        int ncol = column + delColumn[i];
        if (nrow >= 0 && nrow < img.size() && ncol >= 0 && ncol < img[0].size() &&
    img[nrow][ncol] == ogcolor){
        dfsTraversal(img, nrow, ncol, color, ogcolor, delRow, delColumn);
    }
    }
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int ogcolor = image[sr][sc];
    if (ogcolor == color) return image;
    //Do not modify the original array
    vector<vector<int>> img (m, vector<int> (n));
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            img[i][j] = image[i][j];
        }
    }
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delColumn {0, -1, 0, 1};
    dfsTraversal(img, sr, sc, color, ogcolor, delRow, delColumn);
    return img;
}

