#include <bits/stdc++.h>
using namespace std;

class MyQueue{
private:
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        //When the constructor is called, clear the stack
        while (!st1.empty()) st1.pop();
        while (!st2.empty()) st2.pop();
    }

    //O(1)
    void push(int x) {
        st1.push(x);
    }

    //O(N) ~ Worst Case
    int pop() {
        if (st2.empty()){
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }

    //O(N) ~ Worst Case
    int peek() {
        if (st2.empty()){
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    //O(1)
    bool empty() {
        return (st1.empty() && st2.empty());
    }
};
