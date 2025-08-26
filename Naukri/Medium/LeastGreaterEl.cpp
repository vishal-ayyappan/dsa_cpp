#include <bits/stdc++.h>
using namespace std;

//Least Greater Element (Cannot use stack as er require the least greater element)

vector<int> leastGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge (n);
    set<int> s;
    for (int i=n-1; i>=0; i--){
        auto val = s.upper_bound(arr[i]);
        if (val == s.end()) nge[i] = -1;
        else nge[i] = *val;
        s.insert(arr[i]);
    }
    return nge;
}