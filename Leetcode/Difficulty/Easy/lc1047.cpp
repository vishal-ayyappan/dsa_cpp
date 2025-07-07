#include <bits/stdc++.h>
using namespace std;

//Remove All Adjacent Duplicates In String
//Use stack to check if adjacent elements are same

string removeDuplicates(string s) {
    int n = s.length();
    stack<char> st;
    for (int i=0; i<n; i++){
        if (st.empty()) st.push(s[i]);
        else{
            if (s[i] == st.top()) st.pop();
            else st.push(s[i]);
        }
    }
    string res = "";
    while (!st.empty()){
        res = res + st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

//TC - O(N) + O(N) + O(N)
//SC - O(N)

//Approach 2
//We can use the return string itself as a dynamic stack
string removeDuplicates(string s) {
    int n = s.length();
    string res;
    for (int i=0; i<n; i++){
        if (res.length() == 0 || res.back() != s[i]) res.push_back(s[i]);
        else res.pop_back();
    }
    return res;
}

//TC - O(N)
//SC - O(1)