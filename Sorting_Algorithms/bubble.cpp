#include <bits/stdc++.h>
using namespace std;

// You put the largest value at the end, and you continue this until you get to the first element

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            // this will result in the biggest number, go to the last position as the window decreases
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    } 
}

//TC - O(N*N)
//SC - O(1)