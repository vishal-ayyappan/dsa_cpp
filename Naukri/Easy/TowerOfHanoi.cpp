#include <bits/stdc++.h>
using namespace std;

//Tower of Hanoi

void getTower(int n, vector<vector<int>>& ans, int from, int to, int aux){
    if (n == 0) return;
    if (n == 1){
        ans.push_back({from, to});
        return;
    }
    getTower(n-1, ans, from, aux, to);
    ans.push_back({from, to});
    getTower(n-1, ans, aux, to, from);
}

vector<vector<int>> towerOfHanoi(int n){
    int from = 1;
    int to = 3;
    int aux = 2;
    vector<vector<int>> ans;
    getTower(n, ans, from, to, aux);
    return ans;
}