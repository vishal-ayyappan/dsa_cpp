#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    int n = s.length();
    string res;
    int count1 = 0;
    int count2 = 0;
    int i = 0;
    //To make sure that the opening brackets are greater than closing brackets
    while (i < n){
        if (islower(s[i])) res.push_back(s[i]);
        else if (s[i] == '(') {
            count1++;
            res.push_back(s[i]);
        }
        else{
            count2++;
            if (count2 <= count1) res.push_back(s[i]);
            else count2--;
        }
        i++;
    }
    if (count1 == count2) return res;
    //To make sure that the opening brackets has the same count as closing brackets
    string ans;
    int j = res.length()-1;
    while (j >= 0){
        if (res[j] != '(') ans.push_back(res[j]);
        else{
            if (count1 > count2) count1--;
            else ans.push_back(res[j]);
        }
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//TC - O(2N)
//SC - O(N)


//Approach 2
//Store the indexes that has to be removed in a set and remove them all

string minRemoveToMakeValid(string s) {
    int n = s.length();
    stack<int> st;
    unordered_set<int> remove;
    int i = 0;
    //For the opening brackets (Stores unmatched '(')
    while (i < n){
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')'){
            if (!st.empty()) st.pop();
            else{
                //Storing unmatched ')'
                remove.insert(i);
            }
        }
        i++;
    }
    while (!st.empty()){
        remove.insert(st.top());
        st.pop();
    }
    string ans;
    for (int i=0; i<n; i++){
        if (remove.find(i) == remove.end()) ans.push_back(s[i]);
    }
    return ans;
}

//TC - O(2N)
//SC - O(2N)