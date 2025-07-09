#include <bits/stdc++.h>
using namespace std;

//Minimum Rounds to Complete All Tasks

/*
Store all the elements in the map
*/

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> mpp;
    for (int i=0; i<tasks.size(); i++){
        mpp[tasks[i]]++;
    }
    int count = 0;
    bool notPossible = false;
    for (auto it : mpp){
        while (it.second != 0){
            //Have to be greedy, so choose 3 tasks whenever possible
            if (it.second == 1) {
                notPossible = true;
                break;
            }
            else if (it.second == 2 || it.second == 4){
                it.second -= 2;
                count++;
            }
            else{
                it.second -= 3;
                count++;
            }
        }
        if (notPossible) {
            count = -1;
            break;
        }
    }
    return count;
}

//TC - O(N) + O(N)
//SC - O(K)