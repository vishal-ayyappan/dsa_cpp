#include <bits/stdc++.h>
using namespace std;

//Find Building Where Alice and Bob Can Meet

//Range Based Query problem

//You have to build the segment tree
void buildTree(vector<int>& heights, int idx, int left, int right, vector<int>& segTree){
    if (left == right){
        segTree[idx] = left;
        return;
    }
    int middle = left + (right-left)/2;
    buildTree(heights, 2*idx + 1, left, middle, segTree);
    buildTree(heights, 2*idx + 2, middle+1, right, segTree);
    int left_idx = segTree[2*idx + 1];
    int right_idx = segTree[2*idx + 2];
    if (heights[left_idx] > heights[right_idx]) segTree[idx] = left_idx;
    else segTree[idx] = right_idx;
}

//You have to find the range max index for the range
int getRMIQ(vector<int>& heights, vector<int>& segTree, int start, int end, int left, int right, int idx){
    //If it is out of bounds
    if (left > end || right < start) return -1;
    //If it is inside the bound, return the maxIndex (i.e value in the segTree)
    if (left >= start && right <= end) return segTree[idx];
    //If it is overlapping
    int mid = left + (right-left)/2;
    int left_idx = getRMIQ(heights, segTree, start, end, left, mid, 2*idx+1);
    int right_idx = getRMIQ(heights, segTree, start, end, mid+1, right, 2*idx+2);
    if (left_idx == -1) return right_idx;
    if (right_idx == -1) return left_idx;
    if (heights[left_idx] > heights[right_idx]) return left_idx;
    return right_idx;
}

vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size();
    vector<int> segTree (4*n);
    buildTree(heights, 0, 0, n-1, segTree);
    int size = queries.size();
    vector<int> ans (size);
    for (int i=0; i<size; i++){
        int left;
        int right;
        if (queries[i][0] < queries[i][1]){
            left = queries[i][0];
            right = queries[i][1];
        }
        else{
            left = queries[i][1];
            right = queries[i][0];
        }
        //1/ Check if both are in the same building initially
        if (left == right) ans[i] = left;
        //2/ If you can achieve it by one jump (left jumping to right)
        else if (heights[right] > heights[left]) ans[i] = right;
        //3/ If both are jumping
        else{
            int val = -1;
            int start = right + 1;
            int end = n-1;
            while (start <= end){
                int mid = start + (end-start)/2;
                int idx = getRMIQ(heights, segTree, start, mid, 0, n-1, 0);
                if (heights[idx] > heights[left] && heights[idx] > heights[right]) {
                    val = idx;
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            ans[i] = val;
        }
    }
    return ans;
}