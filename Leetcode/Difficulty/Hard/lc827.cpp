#include <bits/stdc++.h>
using namespace std;

//Making A Large Island

class DisjointSet{
    vector<int> parent;
    vector<int> size;
public:
    //Constructor
    DisjointSet(int n){
        for (int i=0; i<n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    //To find the ultimate parent of each node
    int findParent(int node){
        if (node == parent[node]) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    //To do the union of two cells
    void unionBySize(int x, int y){
        int utp_x = findParent(x);
        int utp_y = findParent(y);
        if (utp_x == utp_y) return;
        if (size[utp_x] > size[utp_y]){
            parent[utp_y] = utp_x;
            size[utp_x] += size[utp_y];
        }
        else{
            parent[utp_x] = utp_y;
            size[utp_y] += size[utp_x];
        }
    }
    int getSize(int node){
        return size[node];
    }
    int getMaxSize(){
        int n = size.size();
        int maxi = 1;
        for (int i=0; i<n; i++){
            maxi = max(maxi, size[i]);
        }
        return maxi;
    }
};

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet* mySet = new DisjointSet(n*n);
    set<pair<int, int>> s;
    vector<int> delRow {-1, 0, 1, 0};
    vector<int> delCol {0, -1, 0, 1};
    vector<vector<bool>> visited (n, vector<bool> (n, false));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int row = i;
            int col = j;
            int node = row*n + col;
            if (grid[row][col] == 0){
                s.insert({row, col});
            }
            else{
                visited[row][col] = true;
                //Put it in the union
                for (int k=0; k<4; k++){
                    int nrow = row + delRow[k];
                    int ncol = col + delCol[k];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && visited[nrow][ncol]){
                        int newNode = nrow*n + ncol;
                        mySet->unionBySize(node, newNode);
                    }
                }
            }
        }
    }
    //Now go through each zeros
    if (s.size() == 0) return mySet->getMaxSize();
    int maxi = mySet->getMaxSize();
    for (auto& it : s){
        int row = it.first;
        int col = it.second;
        unordered_set<int> st;
        for (int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            int nodeSize = 0;
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && visited[row][col]){
                int newNode = nrow*n + ncol;
                int utp_newNode = mySet->findParent(newNode);
                st.insert(utp_newNode);
            }
        }
        int area = 1;
        // In the set you store all the parents
        for (auto& item : st){
            area += mySet->getSize(item);
        }
        maxi = max(maxi, area);
    }
    return maxi;
}