#include <bits/stdc++.h>
using namespace std;

//Rat in a Maze (this is DFS + BackTracking)

void getWays(vector<vector<int>>& maze, int row, int col, vector<vector<bool>>& visited, string& ds, vector<string>& ans,
    vector<int>& delRow, vector<int>& delCol){
    //Base Case
    if (row == maze.size() || col == maze[0].size()) return;
    if (row == maze.size()-1 && col == maze[0].size()-1){
        ans.push_back(ds);
        return;
    }
    //Check all 4 ways
    for (int i=0; i<4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        //If it in bound
        if (nrow >= 0 && nrow < maze.size() && ncol >= 0 && ncol < maze[0].size()){
            //If the cell is not visited
            if (!visited[nrow][ncol]){
                //If it is not blocked
                if (maze[nrow][ncol] == 1){
                    if (i == 0) ds.push_back('L');
                    else if (i == 1) ds.push_back('U');
                    else if (i == 2) ds.push_back('R');
                    else ds.push_back('D');
                    visited[nrow][ncol] = true;
                    getWays(maze, nrow, ncol, visited, ds, ans, delRow, delCol);
                    visited[nrow][ncol] = false;
                    ds.pop_back();
                }
            }
        }
    }
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    vector<string> ans;
    string ds;
    visited[0][0] = true;
    getWays(maze, 0, 0, visited, ds, ans, delRow, delCol);
    sort(ans.begin(), ans.end());
    return ans;
}