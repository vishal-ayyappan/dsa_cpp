#include <bits/stdc++.h>
using namespace std;

// The element is inserted at the right index
// Increase the size of the window each time, and traverse through each element backwards in that window

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i=0; i<n; i++){
        for (int j=i; j>0; j--){
            if (arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}

//TC - O(N*N)
//SC - O(1)