#include <bits/stdc++.h>
using namespace std;

//Longest Consecutive Sequence

int longestConsecutive(vector<int>& nums) {
    //Put everything in a set.
    unordered_set<int> st;
    for (int i=0; i<nums.size(); i++){
        st.insert(nums[i]);
    }
    int maxCount = 0;
    for (auto& it : st){
        //Only start the sequence if this number is the starting
        int num = it;
        if (st.find(num-1) == st.end()){
            int count = 0;
            while (st.find(num) != st.end()){
                count++;
                num = num+1;
            }
            maxCount = max(count, maxCount);
        }
    }
    return maxCount;
}

//Avoid Repetitive counting (Neat logic!!)