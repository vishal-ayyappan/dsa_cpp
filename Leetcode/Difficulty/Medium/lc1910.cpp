#include <bits/stdc++.h>
using namespace std;

//Remove all occurences of a substring

//String Simulation

string removeOccurrences(string s, string part) {
    int n = s.length();
    int m = part.length();
    int i = 0;
    string res;
    string ans;
    while (i < n){
        res.push_back(s[i]);
        ans.push_back(s[i]);
        if (res.size() == m){
            if (res == part){
                for (int i=0; i<m; i++){
                    ans.pop_back();
                    res.pop_back();
                }
                int v = ans.size();
                if (v-m+1 >= 0)  res = ans.substr(v-m+1);
                else res = ans;
            }
            else res.erase(res.begin());
        }
        i++;
    }
    return ans;
}