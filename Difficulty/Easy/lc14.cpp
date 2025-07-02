#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    sort(strs.begin(), strs.end());
    string word1 = strs[0];
    string word2 = strs[n-1];
    int l1 = word1.length();
    int l2 = word2.length();
    int minval = min(l1,l2);
    string res = "";
    int i = 0;
    while (i < minval){
        if (word1[i] != word2[i]) break;
        res += word1[i];
        i++;
    }
    return res;
}

//TC - O(min(l1,l2)) + O(NlogN);
//SC - O(1)
