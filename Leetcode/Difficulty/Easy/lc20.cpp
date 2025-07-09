#include <bits/stdc++.h>
using namespace std;

/*
0/ Use a stack to store the elements
*/

bool isValid(string s) {
    int n = s.size();
    stack<char> st;
    int i = 0;
    while (i < n){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else{
            if (st.empty()) return false;
            if (s[i] == ')'){
                if (st.top() == '(') st.pop();
                else return false;
            }
            else if (s[i] == '}'){
                if (st.top() == '{') st.pop();
                else return false;
            }
            else if (s[i] == ']'){
                if (st.top() == '[') st.pop();
                else return false;
            }
        }
        i++;
    }
    if (st.empty()) return true;
    return false;
}

//TC - O(N)
//SC - O(N)


//Approach 2

bool isValid(string s) {
    int n = s.size();
    stack<char> st;
    for (int i=0; i<s.length(); i++){
        //One slight change from approach 1
        if (s[i] == '(') st.push(')');
        else if (s[i] == '{') st.push('}');
        else if (s[i] == '[') st.push(']');
        else{
            if (st.empty()) return false;
            if (s[i] == st.top()) st.pop();
            else return false;
        }
    }
    if (st.empty()) return true;
    return false;
}

//TC - O(N)
//SC - O(N)

