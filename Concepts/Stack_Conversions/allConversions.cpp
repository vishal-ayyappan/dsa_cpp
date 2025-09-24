#include <bits/stdc++.h>
using namespace std;

//Infix to postfix
int getPriority(char oper){
    if (oper == '^') return 2;
    if (oper == '*' || oper == '/') return 1;
    if (oper == '+' || oper == '-') return 0;
    return -1;
}

string infixToPostfix(string& s) {
    string ans;
    stack<char> st;
    int n = s.length();
    int i = 0;
    while (i < n){
        if (isalnum(s[i])){
            ans.push_back(s[i]);
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (st.top() != '('){
                char ch = st.top();
                st.pop();
                ans.push_back(ch);
            }
            st.pop();
        }
        //If it is an operator
        else{
            int priority = getPriority(s[i]);
            if (st.empty() || priority > getPriority(st.top())) st.push(s[i]);
            else{
                while (!st.empty() && priority <= getPriority(st.top())){
                    char ch = st.top();
                    st.pop();
                    ans.push_back(ch);
                }
                st.push(s[i]);
            }
        }
        i++;
    }
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

//Infix to prefix
int getPriority(char oper){
    if (oper == '^') return 2;
    if (oper == '*' || oper == '/') return 1;
    if (oper == '+' || oper == '-') return 0;
    return -1;
}

string infixToPrefix(string s) {
    string ans;
    reverse(s.begin(), s.end());
    int n = s.length();
    for (int i=0; i<n; i++){
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
    stack<char> st;
    int i = 0;
    while (i < n){
        if (isalnum(s[i])){
            ans.push_back(s[i]);
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (st.top() != '('){
                char ch = st.top();
                st.pop();
                ans.push_back(ch);
            }
            st.pop();
        }
        //You should not keep 2 ^ in the stack
        //If it is an operator
        else {  // any operator
            if (s[i] == '^'){
                while (!st.empty() && getPriority(s[i]) <= getPriority(st.top())){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            else{
                while (!st.empty() && getPriority(s[i]) < getPriority(st.top())){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        i++;
    }
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}