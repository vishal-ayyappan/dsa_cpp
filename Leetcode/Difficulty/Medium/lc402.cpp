#include <bits/stdc++.h>
using namespace std;

//Remove K digits

string removeKdigits(string num, int k) {
    string res;
    int n = num.length();
    int i = 0;
    while (i < n && k > 0){
        while (k>0 && res.size() != 0 && num[i] < res.back()){
            res.pop_back();
            k--;
        }
        res.push_back(num[i]); 
        i++;
    }
    if (k == 0){
        for (int j=i; j<n; j++){
            res += num[j];
        }
    }
    else if (i == n){
        while (k != 0) {
            res.pop_back();
            k--;
        }
    }
    int index = 0;
    for (int idx = 0; idx < res.size(); idx++){
        if (res[idx] !='0') break;
        index++;
    }
    string ans = res.substr(index);
    if (ans.size() == 0) return "0";
    return ans;
}