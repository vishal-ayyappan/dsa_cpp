#include <bits/stdc++.h>
using namespace std;

//Approach

/*
0/ Iterate through the matrix, whenever you encounter 1, do a dfs traversal
1/ Make sure you store the (node-base) in the set, so as to take away the duplicates
*/

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int,int>>& nodes, 
    int row, int col, vector<int> delRow, vector<int> delCol){
        visited[row][col] = true;
        nodes.push_back({row,col});
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size()
                && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    dfs(grid, visited, nodes, nrow, ncol, delRow, delCol);
                }
        }

    }

int countDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited (m, vector<bool> (n,false));
    set<vector<pair<int,int>>> st;
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == 1 && !visited[i][j]){
                pair<int,int> base = {i,j};
                vector<pair<int,int>> nodes;
                dfs(grid, visited, nodes, i, j, delRow, delCol);
                for (int k=0; k<nodes.size(); k++){
                    nodes[k].first = nodes[k].first - base.first;
                    nodes[k].second = nodes[k].second - base.second;
                }
                st.insert(nodes);
            }
        }
    }
    return st.size();
}

//TC - O(M*N*log(M*N));
//SC - O(M*N)