#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    private:
        vector<int> parent;
        vector<int> size;
    public:
        DisjointSet(int n){
            for (int i=0; i<n; i++) parent.push_back(i);
            for (int i=0; i<n; i++) size.push_back(1);
        }
        //To get the ultimate parent
        int findParent(int node){
            if (node == parent[node]) return node;
            parent[node] = findParent(parent[node]);
            return parent[node];
        }
        //Union by size
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

//Number of good paths
vector<vector<int>> getAdjList(vector<vector<int>>& edges, int n){
    vector<vector<int>> adjList (n);
    int size = edges.size();
    for (int i=0; i<size; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    //Get the adjacency list
    int n = vals.size();
    DisjointSet* mySet = new DisjointSet(n);
    vector<vector<int>> adjList = getAdjList(edges, n);
    //Set all the nodes as inactive
    vector<bool> isActive (n, false);
    //Store the nodes with its val in the map 
    map<int, vector<int>> mpp;
    for (int i=0; i<n; i++){
        int wt = vals[i];
        mpp[wt].push_back(i);
    }
    //Iterate through the map
    int result = 0;
    for (auto& it : mpp){
        vector<int> arr = it.second;
        for (int& node : arr){
            //make the nodes active
            isActive[node] = true;
        }
        for (int& node: arr){
            for (int& u : adjList[node]){
                //If it is active, unionize
                if (isActive[u]){
                    //Unionize
                    mySet->unionBySize(node, u);
                }
            }
        }
        //Map to store parent and its value
        unordered_map<int, int> parent_map;
        for (int& node : arr){
            //Get the parent of the nodes
            int parent = mySet->findParent(node);
            parent_map[parent]++;
        }
        for (auto& item : parent_map){
            int no_of_el_with_same_parent = item.second;
            int val = no_of_el_with_same_parent * (no_of_el_with_same_parent -1);
            val /= 2;
            result += val;
        }
    }
    return n + result;
}