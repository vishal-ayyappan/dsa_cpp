#include <bits/stdc++.h>
using namespace std;

//Sum of Query II
void getSegTree(int n, int arr[], int idx, int left, int right, vector<int>& segmentTree){
    if (left == right){
        segmentTree[idx] = arr[left];
        return;
    }
    int middle = left + (right-left)/2;
    getSegTree(n, arr, 2*idx + 1, left, middle, segmentTree);
    getSegTree(n, arr, 2*idx + 2, middle+1, right, segmentTree);
    segmentTree[idx] = segmentTree[2*idx + 1] + segmentTree[2*idx + 2];
}

int rangeQuery(int start, int end, int idx, int left, int right, vector<int>& segmentTree){
    //If the range is out of bounds
    if (left > end || right < start) return 0;
    //If it is completely in the bounds
    if (start <= left && end >= right) return segmentTree[idx];
    //If there is overlap
    int middle = left + (right-left)/2;
    return rangeQuery(start, end, 2*idx + 1, left, middle, segmentTree) +
           rangeQuery(start, end, 2*idx + 2, middle+1, right, segmentTree);
}

vector<int> querySum(int n, int arr[], int q, int queries[]) {
    //Get the queries;
    //Get the segment trees
    vector<int> segmentTree (4*n, 0);
    getSegTree(n, arr, 0, 0, n-1, segmentTree);
    vector<int> ans;
    for (int i=0; i<2*q; i+=2){
        int start = queries[i]-1;
        int end = queries[i+1]-1;
        //Find the ans
        int sum = rangeQuery(start, end, 0, 0, n-1, segmentTree);
        ans.push_back(sum);
    }
    return ans;
}