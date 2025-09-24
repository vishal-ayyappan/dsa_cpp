#include <bits/stdc++.h>
using namespace std;

//Range Sum Query - Mutable

class NumArray {
private:
    vector<int> segTree;
    int size;
    void buildTree(vector<int>& nums, int idx, int left, int right, vector<int>& segTree){
        //Base Case
        if (left == right){
            segTree[idx] = nums[left];
            return;
        }
        int middle = left + (right-left)/2;
        buildTree(nums, 2*idx + 1, left, middle, segTree);
        buildTree(nums, 2*idx + 2, middle+1, right, segTree);
        segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
    }
    void updateTree(int index, int val, int idx, int left, int right, vector<int>& segTree){
        if (left == right){
            if (left == index){
                segTree[idx] = val;
            }
            return;
        }
        int middle = left + (right-left)/2;
        //If the index to update is to the left
        if (middle >= index) updateTree(index, val, 2*idx+1, left, middle, segTree);
        //If it is to the right
        else updateTree(index, val, 2*idx+2, middle+1, right, segTree);
        segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
    }
    int rangeQuery(vector<int>& segTree, int start, int end, int left, int right, int idx){
        //If it is out of bounds
        if (start > right || end < left) return 0;
        //If it is in the bounds
        if (left >= start && right <= end) return segTree[idx];
        //If there is overlapping
        int middle = left + (right-left)/2;
        int firstWay = rangeQuery(segTree, start, end, left, middle, 2*idx + 1);
        int secondWay = rangeQuery(segTree, start, end, middle+1, right, 2*idx + 2);
        return firstWay + secondWay;
    }
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        size = n;
        segTree.assign(4*n, 0);
        //Build the segment tree
        buildTree(nums, 0, 0, n-1, segTree);
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, 0, size-1, segTree);
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(segTree, left, right, 0, size-1, 0);
    }
};
