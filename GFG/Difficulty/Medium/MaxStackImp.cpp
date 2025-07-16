#include <bits/stdc++.h>
using namespace std;

//Implementing max stack

class Solution {
  private:
    stack<pair<long long, long long>> st;

  public:
    Solution() {
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        long long maxi = LONG_MIN;
        if (!st.empty()) maxi = st.top().second;
        maxi = max((long long)x, maxi);
        st.push({x,maxi});
    }

    // Remove the top element from the Stack
    void pop() {
        if (st.empty()) st.pop();
    }

        
    // Returns top element of the Stack
    int peek() {
        if (st.empty()) return -1;
        return (int)st.top().first;
    }
        
    // Finds maximum element of Stack
    int getMax() {
        if (st.empty()) return -1;
        return (int)st.top().second;
    }
};

//TC - O(1) for all functions
//SC - O(2N)

//Doing it in O(N)

class Solution {
  private:
    stack<int> st;
    int maxi;

  public:
    Solution() {
        // code here
        while (!st.empty()) st.pop();
        maxi = INT_MIN;
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            maxi = x;
        }
        else{
            if (x > maxi){
                int value = 2*x - maxi;
                maxi = x;
                st.push(value);
            }
            else st.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (st.empty()) return;
        int value = st.top();
        st.pop();
        if (value > maxi){
            maxi = 2*maxi - value;
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        if (st.empty()) return -1;
        int value = st.top();
        if (value > maxi) return maxi;
        return value;

    }
        
    // Finds maximum element of Stack
    int getMax() {
        if (st.empty()) return -1;
        return maxi;
    }
};

