#include <bits/stdc++.h>
using namespace std;

//Brute

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



//Optimal

//No padding needed
//You can reduce SC by making changes in the original grid, but best practice is to
//avoid altering the original input, that is why we use an additional visited matrix

/*
Approach
0/ Check 2s and store their indices
1/ Do multisource BFS on all the nodes where it is 2.
2/ Once you reach a node with value 1, mark that node as visited
3/ If the queue is empty, return count
4/ Keep a count of fresh, initially, and count the no of times you encounter 1 during 
BFS traversal, at the end if count == fresh return minutes else return -1;
*/

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int fresh = 0;
    vector<pair<int,int>> nodes;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == 2){
                nodes.push_back({i,j});
            }
            else if (grid[i][j] == 1){
                fresh++;
            }
        }
    }
    if (fresh == 0) return 0;
    queue<pair<int,int>> q;
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    vector<int> delRow {-1,0,1,0};
    vector<int> delColumn {0,-1,0,1};
    int minute = 0;
    int count = 0;
    for (int i=0; i<nodes.size(); i++){
        q.push({nodes[i].first, nodes[i].second});
        visited[nodes[i].first][nodes[i].second] = true;
    }
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            int row = item.first;
            int column = item.second;
            for (int j=0; j<delRow.size(); j++){
                int nrow = row + delRow[j];
                int ncolumn = column + delColumn[j];
                if (nrow >= 0 && nrow < m && ncolumn >=0 && ncolumn < n
                && grid[nrow][ncolumn] == 1 && !visited[nrow][ncolumn]){
                    q.push({nrow,ncolumn});
                    visited[nrow][ncolumn] = true;
                    count++;
                }
            }
        }
        minute++;
    }
    if (fresh != count) return -1;
    return minute - 1;
}

//TC - (M*N);
//SC - O(M*N)