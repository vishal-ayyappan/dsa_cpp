#include <bits/stdc++.h>
using namespace std;

//Longest String Chain

bool checkAllChar(string& a, string& b){
    //Everything in b should be in a
    int n = a.length();
    int m = b.length();
    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if (b[j] == a[i]){
            i++;
            j++;
        }
        else i++;
    }
    if (j == m) return true;
    return false;
}

int longestStrChain(vector<string>& words) {
    //This is a classic problem of LIS
    //Sort according to size
    int n = words.size();
    //Min heap to store the size and the string
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    for (int i=0; i<n; i++){
        int size = words[i].length();
        string word = words[i];
        pq.push({size, words[i]});
    }
    vector<string> new_words;
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        new_words.push_back(item.second);
    }
    //Once it is sorted by size, we can do LIS
    int maxi = 1;
    int lastIndex = 0;
    vector<int> dp (n, 1);
    vector<int> parent (n, 0);
    for (int i=0; i<n; i++) parent[i] = i;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            //Check if present and check the size
            if (new_words[i].size() == new_words[j].size()+1){
                if (checkAllChar(new_words[i], new_words[j])){
                    int length = 1 + dp[j];
                    if (length > dp[i]){
                        dp[i] = length;
                        parent[i] = j;
                    }
                }
            }
        }
        if (dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    return maxi;
}