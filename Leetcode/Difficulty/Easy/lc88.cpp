#include <bits/stdc++.h>
using  namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = 0;
    if (n == 0) return;
    if (m == 0){
        nums1 = nums2;
        return;
    }
    while (j < n){
        if (nums2[j] < nums1[i]){
            swap(nums1[i], nums2[j]);
            i--;
        }
        j++;
    }
    sort(nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.begin()+m);
    for (int i=m; i<m+n; i++){
        nums1[i] = nums2[i-m];
    }
}


//Another approach, using gap method

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int size = m+n;
    int gap = size/2 + size%2; //This is how you write ceil
    while (gap > 0){
        int left = 0;
        int right = left + gap;
        while (right < size){
            //If left on the left array and right on the right array
            if (left < m && right < m){
                if (nums1[left] > nums1[right]){
                    swap(nums1[left], nums1[right]);
                }
            }
            //If left on the right array and right on the right array
            else if (left >= m && right >= m){
                if (nums2[left-m] > nums2[right-m]){
                    swap(nums2[left-m], nums2[right-m]);
                }
            }
            //If left on the left array and right on the right array
            else{
                if (nums1[left] > nums2[right-m]){
                    swap(nums1[left], nums2[right-m]);
                }
            }
            left++;
            right++;
        }
        if (gap == 1) break;
        gap = gap/2 + gap%2;
    }
    for (int i=m; i<m+n; i++){
        nums1[i] = nums2[i-m];
    }
}