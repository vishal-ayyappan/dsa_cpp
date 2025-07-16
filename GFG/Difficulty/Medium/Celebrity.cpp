#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    vector<int> prospects;
    for (int i=0; i<n; i++){
        bool celebrity = true;
        for (int j=0; j<n; j++){
            //If i does not know anyone then, he can be the celebrity
            if (i != j){
                if (mat[i][j] != 0){
                    celebrity = false;
                    break;
                }
            }
        }
        if (celebrity) prospects.push_back(i);
    }
    if (prospects.size() == 0) return -1;
    for (int i=0; i<prospects.size(); i++){
        int person = prospects[i];
        //Everyone should know the person
        bool confirmCeleb = true;
        for (int i=0; i<n; i++){
            if (mat[i][person] == 0){
                confirmCeleb = false;
                break;
            }
        }
        if (confirmCeleb) return person;
    }
    return -1;
}

//TC - O(N*N)
//SC - O(N)

//Optimal Approach
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    int top = 0;
    int down = n-1;
    while (top < down){
        if (mat[top][down] == 1) top++;
        else if (mat[down][top] == 1) down--;
        else{
            top++;
            down--;
        }
    }
    for (int i=0; i<n; i++){
        if (i != top){
            if (mat[top][i] != 0 || mat[i][top] != 1) return -1;
        }
    }
    return top;
}

//TC - O(N)
//SC - O(1)
