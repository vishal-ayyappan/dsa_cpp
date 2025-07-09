#include <bits/stdc++.h>
using namespace std;

/*
//Brute Force
Do a DFS Traversal for all the nodes with a condition
*/

bool getDfs(vector<vector<int>>& heights, int row, int col, vector<int> delRow, vector<int> delCol,
    vector<vector<bool>>& visited, bool& pacific, bool& atlantic){
        visited[row][col] = true;
        if (row == 0 || col == 0) pacific = true;
        if (row == heights.size()-1 || col == heights[0].size()-1) atlantic = true;
        if (pacific && atlantic) return true;
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < heights.size() && ncol < heights[0].size()
                && heights[nrow][ncol] <= heights[row][col]  && !visited[nrow][ncol]){
                    if (getDfs(heights, nrow, ncol, delRow, delCol, visited, pacific, atlantic)){
                        return true;
                    }
                }
        }
        return false;
    }

bool pacAtl(vector<vector<int>>& heights, int row, int col){
    int m = heights.size();
    int n = heights[0].size();
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    vector<vector<bool>> visited (m , vector<bool> (n,false));
    bool pacific = false;
    bool atlantic = false;
    return getDfs(heights, row, col, delRow, delCol, visited, pacific, atlantic);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;
    int m = heights.size();
    int n = heights[0].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            int node = heights[i][j];
            if (pacAtl(heights, i, j)){
                ans.push_back({i,j});
            }
        }
    }
    return ans;
}

//TC - O(M*N*M*N)


/*
Optimal
0/ Store all the boundaries of pacific and atlantic and do multisource bfs/dfs to check which will 
go to atlantic and pacific separately, and then find the intersection
*/

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col,
    vector<int> delRow, vector<int> delCol){
        visited[row][col] = true;
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < heights.size() && ncol < heights[0].size()
            && heights[nrow][ncol] >= heights[row][col] && !visited[nrow][ncol]){
                dfs(heights, visited, nrow, ncol, delRow, delCol);
            }
        }
    }

void getNodes(vector<vector<int>>& heights, vector<pair<int,int>> ocean, vector<vector<bool>>& visited,
    vector<int> delRow, vector<int> delCol){
    for (int i=0; i<ocean.size(); i++){
        int row = ocean[i].first;
        int col = ocean[i].second;
        if (!visited[row][col]){
            dfs(heights, visited, row, col, delRow, delCol);
        } 
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;
    vector<pair<int,int>> pacific;
    vector<pair<int,int>> atlantic;
    int m = heights.size();
    int n = heights[0].size();
    //Get all the pacific and atlantic boundaries
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (i == 0 || j == 0) pacific.push_back({i,j});
            if (i == m-1 || j == n-1) atlantic.push_back({i,j});
        }
    }
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    vector<vector<bool>> pacificVis (m, vector<bool> (n,false));
    vector<vector<bool>> atlanticVis (m, vector<bool> (n,false));
    getNodes(heights, pacific, pacificVis, delRow, delCol);
    getNodes(heights, atlantic, atlanticVis, delRow, delCol);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (pacificVis[i][j] && atlanticVis[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    return ans;
}

//TC - O(M*N)
//SC - O(M*N)