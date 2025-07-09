#include<bits/stdc++.h>
using namespace std;

//Basic Calculator

int priority(char c) {
    if (c == '-' || c == '+') return 1;
    else return 0;
}

void evaluate(stack<int>& operand, stack<char>& operatorr){
    int first = operand.top();
    operand.pop();
    int second = operand.top();
    operand.pop();
    char op = operatorr.top();
    operatorr.pop();
    int result;
    if (op == '+') result = second + first;
    else result = second - first;
    operand.push(result);
}

int calculate(string s) {
    int n = s.length();
    stack<int> operand;
    // operand.push(0);
    stack<char> operatorr;
    int i = 0;
    while (i < n) {
        // If it is a space
        if (s[i] == ' ') {
            i++;
            continue;
        }
        // If it is a digit
        if (isdigit(s[i])) {
            int number = 0;
            while (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
                i++;
            }
            operand.push(number);
            continue;
        }
        // If it is an operator
        if (s[i] == '('){
            operatorr.push(s[i]);
            i++;
            continue;
        }
        if (s[i] == ')') {
            while (!operatorr.empty() && operatorr.top() != '(') {
                evaluate(operand, operatorr);
            }
            if (!operatorr.empty()) operatorr.pop();
            i++;
            continue;
        } 
        if (s[i] == '+' || s[i] == '-'){
            //Handling unary
            int j = i-1;
            while (j>=0 && s[j] == ' ') j--;
            if (i == 0 || s[j] == '('){
                operand.push(0);
            }
            while (!operatorr.empty() && operatorr.top() != '(' &&
                    priority(s[i]) <= priority(operatorr.top())) {
                evaluate(operand, operatorr);
            }
            operatorr.push(s[i]);
            i++;
            continue;
        }  
    }
    while (!operatorr.empty()) {
        evaluate(operand, operatorr);
    }
    return operand.top();
}

//TC ~ O(N)
//SC - O(2N)