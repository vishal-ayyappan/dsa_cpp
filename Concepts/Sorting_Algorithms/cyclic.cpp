#include <bits/stdc++.h>
using namespace std;

//Cyclic sort

//Sorting from 1 to n
void cyclicSort(vector<int>& nums){
    int n = nums.size();
    for (int i=0; i<n; i++){
        while (nums[i] != i+1){
            swap(nums[i], nums[nums[i]-1]);
        }
    }
}