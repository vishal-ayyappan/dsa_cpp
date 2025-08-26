#include <bits/stdc++.h>
using namespace std;

//Tree Diameter

//Concept 
// 0/ The farthest node from any node of the tree will be one of the diameter
// 1/ Take a random node and get one of the diameter and get the farthest node from that node.
// 2/ Have to do level order traversal

int getMaxDiameter(int n, vector<int> arr) {
    int maxDepth = -1;
    for (int i=0; i<n; i++){
        if (arr[i] > 0) maxDepth = i;
    }
    if (maxDepth == -1) return 0;
    //Check if every level has greater than 2 nodes
    bool canBranch = true;
    for (int i=1; i<=maxDepth; i++){
        if (arr[i] < 2) {
            canBranch = false;
            break;
        }
    }
    if (canBranch) return 2*maxDepth;
    return maxDepth;
}