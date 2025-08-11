#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent;
    vector<int> size;
    int nodes;
    unordered_map<int, int> mpp;
public:
    DisjointSet(int n){
        nodes = n;
        for (int i=0; i<n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    // To find the ultimate parent of the node
    int findParent(int node){
        if (node == parent[node]) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    //To get the union
    bool unionbySize(int x, int y){
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
    int findGroups(){
        for (int i=0; i<nodes; i++){
            parent[i] = findParent(i);
        }
        for (int i=0; i<nodes; i++){
            mpp[parent[i]]++;
        }
        return mpp.size();
    }
};

//Number of Operations to Make Network Connected
int makeConnected(int n, vector<vector<int>>& connections) {
    //Find the connected components (use Kruskals algo to find minimum spanning trees)
    int size = connections.size();
    DisjointSet* mySet = new DisjointSet(n);
    int extra = 0;
    for (int i=0; i<size; i++){
        int u = connections[i][0];
        int v = connections[i][1];
        if (!mySet->unionbySize(u, v)) extra++;
    }
    //Also need to find the number of groups
    int groups = mySet->findGroups();
    //If we have n groups, we must need n-1 extras.
    int needed = groups - 1;
    if (needed > extra) return -1;
    return needed;
}