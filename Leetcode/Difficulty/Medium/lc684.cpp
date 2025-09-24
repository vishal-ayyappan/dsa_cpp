#include <bits/stdc++.h>
using namespace std;

//Redundant Connection

//Union by size
class DisjointSetUnion{
    private:
        vector<int> size;
        vector<int> parent;
    public:
        DisjointSetUnion(int n){
            for (int i=0; i<n; i++){
                size.push_back(1);
                parent.push_back(i);
            }
        }
        //Find the parent
        int findParent(int node){
            if (parent[node] == node) return parent[node];
            int getParent = findParent(parent[node]);
            return parent[node] = getParent;
        }
        //Union by size
        bool unionBySize(int x, int y){
            int utp_x = findParent(x);
            int utp_y = findParent(y);
            if (utp_x == utp_y) return false;
            //If size of x's parent is large
            if (utp_x > utp_y){
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

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    //We can do dsu, if the parents are same, then we can flag that as redundant
    vector<int> ans (2);
    DisjointSetUnion* mySet = new DisjointSetUnion(n+1);
    for (int i=0; i<n; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        if (mySet->unionBySize(x, y) == false) ans = {x,y};
    }
    return ans;

}