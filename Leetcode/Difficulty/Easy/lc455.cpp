#include <bits/stdc++.h>
using namespace std;

//Assign Cookies

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());
    int i = 0;
    int j = 0;
    //Answer variable
    int count = 0;
    while (i < n){
        if (g[i] <= s[j]){
            count++;
            j++;
        }
        i++;
    }
    return count;
}

//TC - O(NlogN) + O(MlogM) + O(N)
//SC - O(1)