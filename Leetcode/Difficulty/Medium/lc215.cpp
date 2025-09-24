#include <bits/stdc++.h>
using namespace std;

//Kth largest element in the array
int findKthLargest(vector<int>& nums, int k) {
    //Put it in the priority queue and pop k times
    priority_queue<int> pq;
    for (int num : nums) pq.push(num);
    while (k > 1) {
        pq.pop();
        k--;
    }
    return pq.top();
}

//Quick Select algo
int getKthLargest(vector<int>& nums, int start, int end, int k){
    if (start == end && start == k-1) return nums[start];
    int pivot = nums[start];
    int left = start+1;
    int right = end;
    while (left <= right){
        while (left <= right && nums[left] <= pivot) left++;
        while (left <= right && nums[right] > pivot) right--;
        if (left < right) swap(nums[left], nums[right]);
    }
    swap(nums[start], nums[right]);
    if (right < k-1) return getKthLargest(nums, right+1, end, k);
    else if (right > k-1) return getKthLargest(nums, start, right-1, k);
    return nums[right];
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return getKthLargest(nums, 0, n-1, n-k+1);
}
