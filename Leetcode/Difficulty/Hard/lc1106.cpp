#include <bits/stdc++.h>
using namespace std;

//Parsing a Boolean Expression

bool parseBoolExpr(string expression) {
    int n = expression.length();
    int i = 0;
    stack<char> st;
    while (i < n){
        if (expression[i] == ','){
            i++;
            continue;
        }
        if (expression[i] != ')') st.push(expression[i]);
        else{
            vector<char> values;
            while (st.top() != '('){
                values.push_back(st.top());
                st.pop();
            }
            st.pop();
            //Operator
            char operatorr = st.top();
            st.pop();
            //OR operator
            int size = values.size();
            int res;
            if (values[0] == 't') res = 1;
            else res = 0;
            if (operatorr == '|'){
                for (int i=1; i<size; i++){
                    if (values[i] == 't') res = res || 1;
                    else res = res || 0;
                }
            }
            else if (operatorr == '&'){
                for (int i=1; i<size; i++){
                    if (values[i] == 't') res = res && 1;
                    else res = res && 0;
                }     
            }
            else{
                res = !res;
            }
            if (res == 1) st.push('t');
            else st.push('f');
        }
        i++;
    }
    if (st.top() == 't') return true;
    return false;
}