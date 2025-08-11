#include <bits/stdc++.h>
using namespace std;

//Kruskals Algorithm


class DisjointSet{
    vector<int> size;
    vector<int> parent;
public:
    //Constructor
    DisjointSet(int n){
        //Initialization
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
    bool unionBySize(int x, int y){
        int utp_x = findParent(x);
        int utp_y = findParent(y);
        if (utp_x == utp_y) return false;
        if (size[utp_x] > size[utp_y]){
            //X would be the ultimate parent
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

//Be Extra careful when you are dealing with custom comparators
struct Compare{
    bool operator()(vector<int>& edges1, vector<int>& edges2){
        return edges1[2] < edges2[2];
    }
};

int kruskalsMST(int V, vector<vector<int>> &edges) {
    //Sort according to the edges
    sort(edges.begin(), edges.end(), Compare());
    int n = edges.size();
    DisjointSet* mySet = new DisjointSet(V);
    int sum = 0;
    for (int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        if (mySet->unionBySize(u, v)){
            sum += wt;
        }
    }
    return sum;
}