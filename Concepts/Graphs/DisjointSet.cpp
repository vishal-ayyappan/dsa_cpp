#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    int n;
public:
    //Constructor
    DisjointSet(int node){
        n = node;
        int size = n+1;
        parent.resize(size);
        rank.resize(size);
        for (int i=0; i<size; i++) parent[i] = i;
        for (int i=0; i<size; i++) rank[i] = 0;
    }
    int findParent(int x){
        if (x == parent[x]) return x;
        parent[x] = findParent(parent[x]);
        return parent[x];
    }
    void unionTwoSets(int x, int y){
        //If both belong to the same group continue, else add
        int utp_x = findParent(x);
        int utp_y = findParent(y);
        if (utp_x == utp_y) return; //If the two nodes belong to the same group, you do not do anything
        if (rank[utp_x] > rank[utp_y]){
            //Connect the smaller rank to the larger rank
            parent[utp_y] = utp_x;
        }
        else if (rank[utp_x] < rank[utp_y]){
            parent[utp_x] = utp_y;
        }
        else{
            parent[utp_y] = utp_x;
            rank[utp_x]++;
        }
    }
};


//Union by size

class DisjointSet{
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        for (int i=0; i<=n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int node){
        if (node == parent[node]) return;
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
};