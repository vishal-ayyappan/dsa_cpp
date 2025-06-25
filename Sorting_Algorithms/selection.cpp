#include <bits/stdc++.h>
using namespace std;

//Concept
// For each index, traverse through the entire array, and swap the minelement and the number in that index;

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i<n-1; i++){
        int minIndex = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// TC - O(N*N)
// SC - O(1)