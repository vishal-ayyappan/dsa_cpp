#include <bits/stdc++.h>
using namespace std;

//Number of Islands 2

class DisjointSet{
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        for (int i=0; i<n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    //To find the ultimate parent
    int findParent(int node){
        if (node == parent[node]) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    //To unionize the elements
    bool unionBySize(int x, int y){
        int utp_x = findParent(x);
        int utp_y = findParent(y);
        if (utp_x == utp_y) return false;
        if (size[utp_x] > size[utp_y]){
            parent[utp_y] = utp_x;
            size[utp_x] += size[utp_y];
        }
        else{
            parent[utp_x] = utp_y;
            size[utp_y] += size[utp_x];
        }
        return true;
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	int total = n*m;
    DisjointSet* mySet = new DisjointSet(total);
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    int size = q.size();
    vector<int> ans(size);
    int count = 0;
    for (int i=0; i<size; i++){
        int row = q[i][0];
        int col = q[i][1];
        if (visited[row][col]){
            ans[i] = count;
            continue;
        }
        visited[row][col] = true;
        int node = row*m + col;
        count++;
        for (int j=0; j<4; j++){
            int nrow = row + delRow[j];
            int ncol = col + delCol[j];
            int new_node = nrow*m + ncol;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol]){
                if (mySet->unionBySize(node, new_node)){
                    count--;
                }
            }
        }
        ans[i] = count;
    }
    return ans;
}