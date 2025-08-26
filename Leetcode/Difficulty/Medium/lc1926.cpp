#include <bits/stdc++.h>
using namespace std;

//Nearest Exit from Entrance in Maze
//Store the row and column in the queue (If it is the border, return the time)
//Do a BFS (Level order)

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    //The entrance does not count as an exit
    int n = maze.size();
    int m = maze[0].size();
    int row = entrance[0];
    int col = entrance[1];
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    int time = 0;
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            int r = item.first;
            int c = item.second;
            if (r == 0 || r == n-1 || c == 0 || c == m-1){
                //If it is at the end and if it is not the entrance coordinates
                if (r != entrance[0] || c != entrance[1]) return time;
            }
            for (int j=0; j<4; j++){
                int nrow = r + delRow[j];
                int ncol = c + delCol[j];
                if (nrow >= 0 && nrow < n && ncol >=0 && ncol < m && maze[nrow][ncol] == '.' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
        time++;
    }
    return -1;
}