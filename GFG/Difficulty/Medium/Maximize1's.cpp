#include <bits/stdc++.h>
using namespace std;

//Maximize number of 1's

int maxOnes(vector<int>& arr, int k) {
    //Do a sliding window approach
    int n = arr.size();
    int left = 0;
    int right = 0;
    int ones = 0;
    while (right < n){
        //If it is one, move forward
        if (arr[right] == 0) {
            k--;
            while (left < n && k < 0){
                //If it is 0, flip it back to 0
                if (arr[left] == 0) k++;
                left++;
            }
        }
        int size = right - left + 1;
        ones = max(ones, size);
        right++;
        
    }
    return ones;
}