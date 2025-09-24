#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str){
    int n = str.length();
    int left = 0;
    int right = 0;
    unordered_map<char, int> mpp;
    int maxi = 0;
    while (right < n){
        //Increase the freq of that character
        mpp[str[right]]++;
        if (mpp.size() > k){
            while (mpp.size() > k){
                mpp[str[left]]--;
                if (mpp[str[left]] == 0){
                    mpp.erase(str[left]);
                }
                left++;
            }
        }
        int length = right - left + 1;
        maxi = max(maxi, length);
        right++;
    }
    return maxi;
}
