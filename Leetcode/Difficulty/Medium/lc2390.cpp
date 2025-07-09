#include<bits/stdc++.h>
using namespace std;

//Removing Stars From a String

string removeStars(string s) {
    int n = s.length();
    string ans;
    for (int i=0; i<n; i++){
        if (s[i] == '*' && ans.size() != 0) ans.pop_back();
        else ans.push_back(s[i]);
    }
    return ans;
}

//TC - O(N)
//SC - O(1)