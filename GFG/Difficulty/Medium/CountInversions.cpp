#include <bits/stdc++.h>
using namespace std;

//Count Inversions (Extended version of merge sort)

int merge(vector<int>& temp, int start, int middle, int end){
    int i = start;
    int j = middle+1;
    int count = 0;
    vector<int> v;
    while (i <= middle && j <= end){
        if (temp[i] > temp[j]){
            v.push_back(temp[j]);
            count += (middle - i + 1); //All the elements to the right of array1 will also have invertions
            j++;
        }
        else{
            v.push_back(temp[i]);
            i++;
        }
    }
    while (i <= middle){
        v.push_back(temp[i]);
        i++;
    }
    while (j <= end){
        v.push_back(temp[j]);
        j++;
    }
    int idx = 0;
    for (int i=start; i<=end; i++){
        temp[i] = v[idx];
        idx++;
    }
    return count;
}

int getCount(vector<int>& temp, int start, int end){
    if (start >= end) return 0;
    int middle = start + (end-start)/2;
    int left = getCount(temp, start, middle);
    int right = getCount(temp, middle+1, end);
    int value = merge(temp, start, middle, end);
    return left + right + value;
}

int inversionCount(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp = arr;
    return getCount(temp, 0, n-1);
}