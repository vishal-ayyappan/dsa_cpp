#include <bits/stdc++.h>
using namespace std;

//Range Minimum Query
void getSegTree(int arr[], int idx, int left, int right, int segTree[]){
    //Base Case
    if (left == right) {
        segTree[idx] = arr[left];
        return;
    }
    int middle = left + (right-left)/2;
    getSegTree(arr, 2*idx + 1, left, middle, segTree);
    getSegTree(arr, 2*idx + 2, middle+1, right, segTree);
    segTree[idx] = min(segTree[2*idx + 1],segTree[2*idx + 2]);
}

int *constructST(int arr[], int n) {
    int* segTree = new int[4*n]; //Allocate the array dynamically
    //If you do local allocation, it will get destroyed after the function ends
    getSegTree(arr, 0, 0, n-1, segTree);
    return segTree;
}

/* The functions returns the
 min element in the range
 from a and b */

int getMin(int st[], int start, int end, int left, int right, int idx){
    //If it is out of bounds
    if (right < start || left > end) return INT_MAX;
    //If it is in bounds
    if (left >= start && right <= end) return st[idx];
    //If it is overlapping, go to both the child
    int middle = left + (right-left)/2;
    int oneWay = getMin(st, start, end, left, middle, 2*idx + 1);
    int twoWay = getMin(st, start, end, middle+1, right, 2*idx + 2);
    return min(oneWay, twoWay);
}

int RMQ(int st[], int n, int a, int b) {
    //n is the size of the original array
    //It has the same algo as range sum query
    int result = getMin(st, a, b, 0, n-1, 0);
    return result;
}