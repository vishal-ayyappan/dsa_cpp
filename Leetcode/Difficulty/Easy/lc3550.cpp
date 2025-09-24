#include <bits/stdc++.h>   
using namespace std;

//Smallest Index With Digit Sum Equal to Index

class Solution {
private:
    int getSum(int num){
        int sum = 0;
        while (num != 0){
            int digit = num % 10;
            num = num / 10;
            sum += digit;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++){
            int getVal = getSum(nums[i]);
            if (getVal == i) return i;
        }
        return -1;
    }
};