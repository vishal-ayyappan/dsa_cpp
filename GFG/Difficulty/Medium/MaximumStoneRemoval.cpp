#include <bits/stdc++.h>
using namespace std;

//Maximum Stone Removal

class DisjointSet{
    vector<int> parent;
    vector<int> size;
    public:
        //Constructor
        DisjointSet(int n){
            for (int i=0; i<n; i++) {
                parent.push_back(i);
                size.push_back(1);
            }
        }
        //Find the ultimate parent
        int findParent(int node){
            if (node == parent[node]) return node;
            parent[node] = findParent(parent[node]);
            return parent[node];
        }
        //Unionize by size
        void unionBySize(int x, int y){
            int utp_x = findParent(x);
            int utp_y = findParent(y);
            //If both are already connected
            if (utp_x == utp_y) return;
            //If not
            if (size[utp_x] > size[utp_y]){
                parent[utp_y] = utp_x;
                size[utp_x] += size[utp_y];
            }
            else{
                parent[utp_x] = utp_y;
                size[utp_y] += size[utp_x]; 
            }
        }
        //Get the number of components
        int getComponents(unordered_set<int>& active){
            unordered_set<int> s;
            for (auto& it : active){
                int par = findParent(it);
                s.insert(par);
            }
            return s.size();
        }
};

int maxRemove(vector<vector<int>>& stones, int n) {
    //Find the maxRow and maxCol
    int maxRow = 0;
    int maxCol = 0;
    for (int i=0; i<n; i++){
        int row = stones[i][0];
        int col = stones[i][1];
        maxRow = max(maxRow, row);
        maxCol = max(maxCol, col);
    }
    // Denote each row and column with a number
    unordered_set<int> active;
    DisjointSet* mySet = new DisjointSet(maxRow + maxCol + 2);
    // Unionize the row and column
    for (int i=0; i<n; i++){
        int row = stones[i][0];
        int rowNode = row;
        int col = stones[i][1];
        int colNode = maxRow + 1 + col;
        mySet->unionBySize(rowNode, colNode);
        active.insert(rowNode);
        active.insert(colNode);

    }
    // Get the number of components
    int comp_size = mySet->getComponents(active);
    // Make sure you only have one stone for each component
    return n - comp_size;
}