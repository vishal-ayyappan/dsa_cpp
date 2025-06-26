#include <bits/stdc++.h>
using namespace std;

/*
Approach
0/ Pad the grid with zeros
1/ Traverse through the grid, and store the row indexes where 2's are located
2/ Do BFS simultanously for all the 2 nodes and update the visited array, that 
would be 1 minute
3/ If the queue is empty, return count
4/ Traverse the grid once again and if 1 exists, return -1 else return count
*/

vector<pair<int,int>> get2s(vector<vector<int>> grid){
    vector<pair<int,int>> ans;
    int m = grid.size();
    int n = grid[0].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == 2){
                ans.push_back({i,j});
            } 
        }
    }
    return ans;
}

bool check1(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == 1) return true;
        }
    }
    return false;
}

int getMinutes(vector<vector<int>>& grid, vector<pair<int,int>> nodes){
    int minute = 0;
    queue<pair<int,int>> q;
    for (int i=0; i<nodes.size(); i++){
        q.push({nodes[i].first, nodes[i].second});
    }
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            int row = item.first;
            int column = item.second;
            if (grid[row+1][column] == 1) {
                q.push({row+1, column});
                grid[row+1][column] = 2;
            }
            if (grid[row-1][column] == 1) {
                q.push({row-1, column});
                grid[row-1][column] = 2;
            }
            if (grid[row][column+1] == 1) {
                q.push({row, column+1});
                grid[row][column+1] = 2;
            }
            if (grid[row][column-1] == 1) {
                q.push({row, column-1});
                grid[row][column-1] = 2;
            }
        }
        minute++;  
    }
    if (check1(grid)) return -1;
    else return minute-1;
}

void paddedgrid(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    //Pad left and right
    for (int i=0; i<m; i++){
        grid[i].insert(grid[i].begin(),0);
        grid[i].push_back(0);
    }
    //Pad top and bottom
    vector<int> zeros(n+2, 0);
    grid.insert(grid.begin(), zeros);
    grid.push_back(zeros);
}


int orangesRotting(vector<vector<int>>& grid) {
    paddedgrid(grid);
    vector<pair<int,int>> nodes = get2s(grid);
    if (!check1(grid)) return 0;
    if (nodes.size() == 0) return -1;
    return getMinutes(grid, nodes);
}