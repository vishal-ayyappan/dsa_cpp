#include <bits/stdc++.h>
using namespace std;

//Sort An Array of 0s, 1s and 2s (Dutch National Flag Algorithm  )

void sortArray(vector<int>& arr, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while (mid <= high){
        //if the mid value is 0
        if (arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) mid++;
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
