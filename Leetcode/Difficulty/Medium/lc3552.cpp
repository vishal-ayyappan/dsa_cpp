#include <bits/stdc++.h>
using namespace std;

//Grid Teleportation Traversal (Heavy question)
//For (0 1 edges bfs, you use dequeue)

//DFS + Backtracking
int getMoves(vector<string>& matrix,
                 unordered_map<char, vector<pair<int, int>>>& teleport, int row,
                 int col, vector<int>& delRow, vector<int>& delCol,
                 vector<vector<bool>>& visited) {
        int ch = matrix[row][col];
        // If there is a blockage
        if (ch == '#') return INT_MAX;
        if (row == matrix.size() - 1 && col == matrix[0].size() - 1) return 0;
        visited[row][col] = true;
        int mini = INT_MAX;
        // If there is a portal
        if (ch != '.') {
            for (auto& it : teleport[ch]) {
                int nrow = it.first;
                int ncol = it.second;
                if (nrow == row && ncol == col)
                    continue;
                if (!visited[nrow][ncol]) {
                    int move_val = getMoves(matrix, teleport, nrow, ncol,
                                            delRow, delCol, visited);
                    mini = min(mini, move_val);
                }
            }
        }
        // If there is a dot
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < matrix.size() &&
                ncol < matrix[0].size() && !visited[nrow][ncol]) {
                int move_val = getMoves(matrix, teleport, nrow, ncol,
                                        delRow, delCol, visited);
                if (move_val != INT_MAX) {
                    mini = min(mini, 1 + move_val);
                }
            }
        }
        visited[row][col] = false;
        return mini;
    }

int minMoves(vector<string>& matrix) {
        unordered_map<char, vector<pair<int, int>>> teleport;
        int n = matrix.size();
        int m = matrix[0].size();
        // Get the indices for teleportation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '.' || matrix[i][j] == '#')
                    continue;
                char ch = matrix[i][j];
                teleport[ch].push_back({i, j});
            }
        }
        // We do a DFS
        vector<int> delRow{-1, 0, 1, 0};
        vector<int> delCol{0, -1, 0, 1};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int result = getMoves(matrix, teleport, 0, 0, delRow, delCol, visited);
        if (result == INT_MAX) return -1;
        return result;
    }


//BFS
//We have to get the minimum time
int minMoves(vector<string>& matrix) {
    unordered_map<char, vector<pair<int, int>>> teleport;
    int n = matrix.size();
    int m = matrix[0].size();
    // Get the indices for teleportation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.' || matrix[i][j] == '#')
                continue;
            char ch = matrix[i][j];
            teleport[ch].push_back({i, j});
        }
    }
    vector<int> delRow{-1, 0, 1, 0};
    vector<int> delCol{0, -1, 0, 1};
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    unordered_set<char> used;
    // We do a BFS
    deque<vector<int>> q;
    q.push_back({0, 0, 0});
    distance[0][0] = 0;
    while (!q.empty()){
        auto item = q.front();
        q.pop_front();
        int row = item[0];
        int col = item[1];
        int moves = item[2];
        if (moves != distance[row][col]) continue;
        if (row == n-1 && col == m-1) return moves;
        char ch = matrix[row][col];
        //If it is a portal
        if (ch != '#' && ch != '.' && !used.count(ch)){
            for (auto& it : teleport[ch]){
                int nrow = it.first;
                int ncol = it.second;
                if (nrow == row && ncol == col) continue;
                if (distance[nrow][ncol] > moves){
                    distance[nrow][ncol] = moves;
                    q.push_front({nrow, ncol, moves});
                }
            }
            //You can only use the portal letter once
            used.insert(ch);
        }
        //Iterate all 4 directions as well
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && matrix[nrow][ncol] != '#'){
                if (distance[nrow][ncol] > moves + 1){
                    distance[nrow][ncol] = moves + 1;
                    q.push_back({nrow, ncol, moves+1});
                }
            }
        }
    }
    return -1;
}
