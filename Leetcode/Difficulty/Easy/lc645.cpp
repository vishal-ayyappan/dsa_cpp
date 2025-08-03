#include <bits/stdc++.h>
using namespace std;

//Using Bit Manipulation (XOR techique)

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int xorVal = 0;
    for (int i=1; i<=n; i++) xorVal = xorVal ^ i;
    for (int i=0; i<n; i++) xorVal = xorVal ^ nums[i];
    //The number xorVal will never be zer (i.e it will be set at least one bit);
    //Get any set bit index
    int setBitIndex = -1;
    for (int bit=0; bit<32; bit++){
        if ((xorVal >> bit) & 1){
            setBitIndex = bit;
            break;
        }
    }
    //Group the values that have setBitIdx = 0 and setBotIdx = 1, separately
    int ones = 0;
    int zeros = 0;
    for (int i=1; i<=n; i++){
        //If the bit is set at that index
        if ((i>>setBitIndex) & 1) ones = ones ^ i;
        else zeros = zeros ^ i;
    }
    for (int i=0; i<n; i++){
        //If the bit is set at that index
        if ((nums[i]>>setBitIndex) & 1) ones = ones ^ nums[i];
        else zeros = zeros ^ nums[i];
    }
    // Ones and Zeros will contain the missing and repeating, but dk which contains which
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (nums[i] == ones){
            cnt++;
        }
    }
    if (cnt == 2) return {ones, zeros};
    return {zeros, ones};
}