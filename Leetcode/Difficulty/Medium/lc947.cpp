#include <bits/stdc++.h>
using namespace std;

//Classic Disjoint Set Problem

class DisjointSet{
    vector<int> parent;
    vector<int> size;
    int nodes;
    unordered_map<int, int> mpp;
public:
    //Constructor
    DisjointSet(int n){
        nodes = n;
        for (int i=0; i<n; i++){
            size.push_back(1);
            parent.push_back(i);
        }
    }
    int findParent(int node){
        if (node == parent[node]) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
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
    int components(){
        for (int i=0; i<nodes; i++) parent[i] = findParent(i);
        for (int i=0; i<nodes; i++) mpp[parent[i]]++;
        int count = 0;
        for (auto& it : mpp){
            if (it.second > 1){
                count++;
            }
        }
        return count;
    }
};

//Most Stones Removed with Same Row or Column
int getMaxRow(vector<vector<int>>& stones){
    int n = stones.size();
    int maxi = INT_MIN;
    for (int i=0; i<n; i++){
        maxi = max(maxi, stones[i][0]);
    }
    return maxi;
}

int getMaxCol(vector<vector<int>>& stones){
    int n = stones.size();
    int maxi = INT_MIN;
    for (int i=0; i<n; i++){
        maxi = max(maxi, stones[i][1]);
    }
    return maxi;
}

int removeStones(vector<vector<int>>& stones) {
    // 0/ Find the max row and column
    int maxRow = getMaxRow(stones);
    int maxCol = getMaxCol(stones);
    DisjointSet* mySet = new DisjointSet(maxRow + maxCol + 2);
    // 1/ Marking the column as singleton elements
    // The row goes from 0 to maxRow-1
    // The column goes from maxRow to maxRow + maxCol - 1;
    // Create a disjoint set union ds, such that whenever you encounter a stone coordinate, unionize the row and the column
    int size = stones.size();
    for (int i=0; i<size; i++){
        int row = stones[i][0];
        int col = stones[i][1];
        int alter_row = row;
        int alter_col = maxRow + 1 + col;
        //Unionize all the stone coordinates
        mySet->unionBySize(alter_row, alter_col);
    }   
    //Check the number of connected components
    int components = mySet->components();
    // Each component should have only 1 stone
    return size - components;
}