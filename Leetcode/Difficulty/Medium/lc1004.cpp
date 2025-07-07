#include <bits/stdc++.h>
using namespace std;

//Max Consecutive ones III

//My approach

/*
You can flip at most 2 zeros
Find the longest subarray, with atmost 2 zeros
*/

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    int maxLen = 0;
    queue<int> q;
    while (right < n){
        if (nums[right] == 1) {
            maxLen = max(maxLen, right-left+1);
        }
        else{
            if (k == 0) left = right+1;
            else{
                q.push(right);
                if (q.size() <= k){ 
                    maxLen = max(maxLen, right-left+1);
                }
                else{
                    left = q.front() + 1;
                    q.pop();
                }
            }
        }
        right++;
    }
    return maxLen;
}

//TC - O(N)
//SC - O(N)


//Brute

//Generate all the subarrays starting with each index, that has atmost 2 zeros

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;
    for (int i=0; i<n; i++){
        int zeros = 0;
        for (int j=i; j<n; j++){
            if (nums[j] == 0) zeros++;
            if (zeros > k) break;
            maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
}

//TC - O(N*N)
//SC - O(1)

//Approach 3 (Following the normal template)

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    int zeros = 0;
    int maxLen = 0;
    while (right < n){
        if (nums[right] == 0) zeros++;
        while (zeros > k){
            if (nums[left] == 0) zeros--;
            left++;
        }
        if (zeros <= k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}

//TC - O(N) + O(N)
//SC - O(1)

//Optimal solution

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    int zeros = 0;
    int maxLen = 0;
    while (right < n){
        if (nums[right] == 0) zeros++;
        if (zeros > k){
            if (nums[left] == 0) zeros--;
            left++;
        }
        if (zeros <= k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}



