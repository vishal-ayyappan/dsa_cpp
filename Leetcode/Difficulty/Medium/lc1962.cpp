#include <bits/stdc++.h>
using namespace std;

//Remove Stones to Minimize the Total

int minStoneSum(vector<int>& piles, int k) {
    int n = piles.size();
    //Put everything in the heap
    priority_queue<int> pq;
    for (int i=0; i<n; i++) pq.push(piles[i]);
    while (k > 0){
        int pile = pq.top();
        pq.pop();
        int remove = pile/2;
        pq.push(pile-remove);
        k--;
    }
    int sum = 0;
    while (!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    return sum;
}