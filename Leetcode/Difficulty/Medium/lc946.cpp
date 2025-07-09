#include <bits/stdc++.h>
using namespace std;

//Put the pushed elements in the stack till the element is equal to pop
//Go through each popped, if its there in the stack, then pop

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    int m = popped.size();
    stack<int> st;
    int i = 0;
    int j = 0;
    while (i < n){
        while (i<n && pushed[i] != popped[j]){
            st.push(pushed[i]);
            i++;
        }
        if (i<n){
            st.push(pushed[i]);
            i++;
        }
        while (j<m && !st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }
    }
    if (!st.empty()) return false;
    return true;
}

//TC - O(N)
//SC - O(N)