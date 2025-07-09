#include <bits/stdc++.h>
using namespace std;

//Reverse Substrings Between Each Pair of Parentheses
//Given that all parenthesis are balanced

string reverseParentheses(string s) {
    int n = s.length();
    stack<int> st;
    int i = 0;
    while (i < n){
        //Store the indices of the '(' in the stack
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')'){
            int lastIdx = i;
            int firstIdx = st.top();
            st.pop();
            reverse(s.begin()+firstIdx, s.begin()+lastIdx);
        }
        i++;
    }
    string ans;
    for (int i=0; i<n; i++){
        if (s[i] == '(' || s[i] == ')') continue;
        else ans.push_back(s[i]);
    }
    return ans;
}

//TC - O(2N)
//SC - O(N)