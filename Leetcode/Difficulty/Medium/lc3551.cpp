#include <bits/stdc++.h>
using namespace std;

//Minimum Swaps to Sort by Digit Sum

struct Comparator{
    bool operator()(auto& a, auto& b){
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};

int getDigitSum(int num){
    int sum = 0;
    while (num != 0){
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }
    return sum;
}

int minSwaps(vector<int>& nums) {
    //Sort by digit sum and nums if digit sum is same
    vector<vector<int>> ds;
    int n = nums.size();
    for (int i=0; i<n; i++){
        int digSum = getDigitSum(nums[i]);
        ds.push_back({digSum, nums[i], i});
    }
    //Sort it according to digSum
    sort(ds.begin(), ds.end(), Comparator());
    //Store the indexes of the new positions in the map
    vector<int> pos (n);
    for (int i=0; i<n; i++){
        pos[i] = ds[i][2];
    }
    //Do cyclic sort on pos (to get the min swaps)
    int count = 0;
    for (int i=0; i<n; i++){
        while (pos[i] != i){
            //Swap
            swap(pos[i], pos[pos[i]]);
            count++;
        }
    }
    return count;
}