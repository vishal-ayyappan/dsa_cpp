#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    private:
        vector<int> size;
        vector<int> parent;
    public:
        DisjointSet(int n){
            for (int i=0; i<n; i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }
        int getParent(int node){
            if (node == parent[node]) return node;
            parent[node] = getParent(parent[node]);
            return parent[node];
        }
        void getUnionByOrder(int x, int y){
            int utp_x = getParent(x);
            int utp_y = getParent(y);
            if (utp_x == utp_y) return;
            //To maintain the lexicographic order
            if (utp_x > utp_y) parent[utp_x] = utp_y;
            else parent[utp_y] = utp_x;
        }
};

//Lexicographically Smallest Equivalent String
string smallestEquivalentString(string s1, string s2, string baseStr) {
    //This is a classic DSU problem
    int letters = 26;
    DisjointSet* mySet = new DisjointSet(letters);
    //Unionize the letters
    int n = s1.length();
    for (int i=0; i<n; i++){
        char ch1 = s1[i];
        char ch2 = s2[i];
        mySet->getUnionByOrder(ch1-'a', ch2-'a');
    }
    string ans;
    int size = baseStr.size();
    for (int i=0; i<size; i++){
        char ch = baseStr[i];
        int par = mySet->getParent(ch - 'a');
        char newChar = (char)('a'+par);
        ans.push_back(newChar);
    }
    return ans;
}