#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string encode(vector<string>& s) {
            int n = s.size();
            string enc = "";
            for (int i=0; i<n; i++) enc = enc + s[i] + "#";   
            enc.pop_back(); 
            return enc;
        }

        vector<string> decode(string& s) {
            vector<string> ans;
            stringstream ss(s);
            string token;
            while (getline(ss, token, '#')){
                ans.push_back(token);
            }
            return ans;
        }
};