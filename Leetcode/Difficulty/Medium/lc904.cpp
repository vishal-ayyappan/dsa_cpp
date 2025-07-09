#include <bits/stdc++.h>
using namespace std;

/*
Fruits into Baskets
aka Find the largest subarray containing atmost 2 distinct elements
*/

int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    int left = 0;
    int right = 0;
    int maxLen = 0;
    //Hashmap to store the frequency of each value
    unordered_map<int, int> mpp;
    while (right < n){
        mpp[fruits[right]]++;
        while (mpp.size() > 2){
            fruits[left]--;
            if (mpp[fruits[left]] == 0){
                mpp.erase(fruits[left]);
            }
            left++;
        }
        if (mpp.size() <= 2){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;    
}