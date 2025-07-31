#include <bits/stdc++.h>
using namespace std;

//Kth Smallest Product of Two Sorted Arrays (Binary Search on answers)

//Generate the number of smallest elements less than middle
long long getKvalue(vector<int>& nums1, vector<int>& nums2, long long target){
    int n = nums1.size();
    int m = nums2.size();
    long long count = 0;
    //Do a binary search on the second array
    for (int i=0; i<n; i++){
        if (nums1[i] > 0){
            long long start = 0;
            long long end = m-1;
            long long counti = 0;
            while (start <= end){
                long long middle = start + (end-start)/2;
                if (1LL*nums1[i]*nums2[middle] <= target){
                    counti = middle + 1;
                    start = middle + 1;
                }
                else end = middle - 1;
            }
            count += counti;
        }
        //If the number is negative, the logic reverses
        else{
            long long start = 0;
            long long end = m-1;
            long long counti = 0;
            while (start <= end){
                long long middle = start + (end-start)/2;
                if (1LL*nums1[i]*nums2[middle] <= target){
                    end = middle - 1;
                    counti = m - middle;
                }
                else start = middle + 1;
            }
            count += counti;
        }
    }
    return count;
}

long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    long long start = -1e12;
    long long end = 1e12;
    while (start <= end){
        long long middle = start + (end-start)/2;
        long long est_k = getKvalue(nums1, nums2, middle);
        if (est_k >= k) end = middle - 1;
        else start = middle + 1;
    }
    return start;
}