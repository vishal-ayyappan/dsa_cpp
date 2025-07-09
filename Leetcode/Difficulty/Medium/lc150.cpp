#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    stack<int> st;
    for (int i=0; i<n; i++){
        string str = tokens[i];
        //Check if number
        if (isdigit(str[str.size() -1])){
            int number = 0;
            bool isNegative = false;
            for (int i=0; i<str.size(); i++){
                if (i == 0 && !isdigit(str[i])) {
                    isNegative = true;
                    continue;
                }
                number = number*10 + (str[i] - '0');
            }
            if (isNegative) number = -number;
            st.push(number);
        }
        else{
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            int result;
            if (str == "+") result = second + first;
            else if (str == "-") result = second - first;
            else if (str == "*") result = second * first;
            else result = second / first;
            st.push(result);
        }
    }
    return st.top();
}

//TC ~ O(N*K) K -> size of the string which is a number
//SC - O(N)