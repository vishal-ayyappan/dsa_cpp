#include <bits/stdc++.h>
using namespace std;

//Accounts Merge

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
    //To unionize
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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    //Go through the accounts and store it in the map
    int n = accounts.size();
    unordered_map<string, int> mpp;
    //Initializing each account as singleton node
    DisjointSet* mySet = new DisjointSet(n);
    for (int i=0; i<n; i++){
        int size = accounts[i].size();
        for (int j=1; j<size; j++){
            string email = accounts[i][j];
            //If the string is not seen before
            if (mpp.find(email) == mpp.end()){
                //Add it to the map
                mpp[email] = i;
            }
            //If the string is already seen, unionize the account
            else{
                mySet->unionBySize(mpp[email], i);
            }
        }
    }
    unordered_map<int, vector<string>> order;
    for (auto& it : mpp){
        string mail = it.first;
        int node = it.second;
        int belongsTo = mySet->findParent(node);
        order[belongsTo].push_back(mail);
    }
    vector<vector<string>> ans;
    for (auto& it : order){
        int node = it.first;
        string name = accounts[node][0];
        sort(it.second.begin(), it.second.end());
        it.second.insert(it.second.begin(), name);
        ans.push_back(it.second);
    }
    return ans;
}