#include <bits/stdc++.h>
using namespace std;

// 01 Matrix

/*
Approach
1/ Create a new copy of the array that you return
2/ Whenever, you encounter 1 in the original array, do a BFS to get the distance
3/ Cannot do dfs because we need the minimum distance to 0
*/

int findDistance(vector<vector<int>>& mat, int row, int col){
    int m = mat.size();
    int n = mat[0].size();
    int count = 0;
    queue<pair<int,int>> q;
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    q.push({row,col});
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            int r = item.first;
            int c = item.second;
            if (mat[r][c] == 0) return count;
            for (int j=0; j<4; j++){
                int nrow = r + delRow[j];
                int ncol = c + delCol[j];
                if (nrow >= 0 && nrow < mat.size() && ncol >= 0 && ncol < mat[0].size()
            && !visited[nrow][ncol]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
        count++;
    }
    return -1;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ans (m, vector<int> (n));
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (mat[i][j] == 1){
                ans[i][j] = findDistance(mat, i, j);
            }
        }
    }
    return ans;
}

//TC - O(N*N*N)
//SC - O(N*N)

//Optimal solution

/*
Do multisource BFS with nodes 0 and push 1
*/

void getDistance(vector<vector<int>>& ans, vector<vector<int>>& mat){
    int m = ans.size();
    int n = ans[0].size();
    vector<pair<int,int>> nodes;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (ans[i][j] == 0){
                nodes.push_back({i,j});
            }
        }
    }
    int count = 0;
    queue<pair<int,int>> q;
    vector<int> delRow {-1,0,1,0};
    vector<int> delCol {0,-1,0,1};
    vector<vector<bool>> visited (m, vector<bool> (n,false));
    for (int i=0; i<nodes.size(); i++){
        q.push({nodes[i].first, nodes[i].second});
    }
    while (!q.empty()){
        int size = q.size();
        for (int i=0; i<size; i++){
            auto item = q.front();
            q.pop();
            int r = item.first;
            int c = item.second;
            ans[r][c] = count;
            for (int j=0; j<4; j++){
                int nrow = r + delRow[j];
                int ncol = c + delCol[j];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                mat[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
        count++;
    }

}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ans (m, vector<int> (n));
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            ans[i][j] = mat[i][j];
        }
    }
    getDistance(ans, mat);
    return ans;
}

//TC - O(M*N)
//SC - O(M*N)