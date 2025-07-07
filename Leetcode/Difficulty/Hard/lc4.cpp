#include<bits/stdc++.h>
using namespace std;

/*
Median of 2 sorted arrays
*/

//Brute 
/*
0/ Use extra space to sort and then find the median
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> sorted;
    while (i<m && j<n){
        if (nums1[i] <= nums2[j]){
            sorted.push_back(nums1[i]);
            i++;
        }
        else{
            sorted.push_back(nums2[j]);
            j++;
        }
    }
    while (i<m){
        sorted.push_back(nums1[i]);
        i++;
    }
    while (j<n){
        sorted.push_back(nums2[j]);
        j++; 
    }
    int size = sorted.size();
    //If it is odd
    if (size&1){
        int idx = size/2;
        return sorted[idx];
    }
    int idx1 = size/2;
    int idx2 = idx1 - 1;
    return (sorted[idx1] + sorted[idx2])/2;
}

//TC - O(max(N,M))
//SC - O(M+N)


//Better
/*
Sort the array without any extra space and then get the median
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int i = m-1;
    int j = 0;
    while (i>=0 && j<n){
        if (nums2[j] < nums1[i]){
            swap(nums2[j], nums1[i]);
            j++;
            i--;
        }
        else{
            j++;
        }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int size = m+n;
    if (size&1){
        int idx = size/2;
        if (idx < m) return nums1[idx];
        else return nums2[idx-m];
    }
    int idx1 = size/2;
    int idx2 = idx1 - 1;
    int first;
    int second;
    if (idx1 < m) first = nums1[idx1];
    else first = nums2[idx1-m];
    if (idx2 < m) second = nums1[idx2];
    else second = nums2[idx2-m];
    return (double)(first+second)/2.0;
}

//TC - O(N) + O(NlogN) + O(MlogM)
//SC - O(1)



//Optimal

/*
Binary Search on Answers (Kinda Brilliant)
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    int barrier = (m+n+1)/2;
    //Binary search on answers
    int start = 0;
    int end = m;
    while (start <= end){
        int middle = start + (end-start)/2;
        //No of elements from the first array
        int cut1 = middle;
        //No of elements from the second array
        int cut2 = barrier - middle;
        int l1 = (cut1 != 0) ? nums1[cut1 - 1] : INT_MIN;
        int r1 = (cut1 != m) ? nums1[cut1] : INT_MAX;
        int l2 = (cut2 > 0) ? nums2[cut2 - 1] : INT_MIN;
        int r2 = (cut2 < n) ? nums2[cut2] : INT_MAX;
        if (l1 <= r2 && l2 <= r1){
            int size = m+n;
            if (size&1) return max(l1,l2);
            else return (double) (max(l1,l2) + min(r1,r2))/2.0;
        }
        if (l1 > r2) end = middle - 1;
        else start = middle + 1;
    }
    return 0.0;
}

//TC - O(log(min(M,N)))
//SC - O(1)
