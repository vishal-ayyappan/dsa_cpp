#include <bits/stdc++.h>
using namespace std;

int lcp(string word1, string word2){
    int m = min(word1.length(), word2.length());
    int temp = 0;
    int j = 0;
    while (j < m){
        if (word1[j] != word2[j]) break;
        temp++;
        j++;
    }
    return temp;
}

vector<int> adjacentPrefix(vector<string>& words){
    int n = words.size();
    vector<int> ans;
    for (int i=0; i<n-1; i++){
        ans.push_back(lcp(words[i], words[i+1]));
    }
    return ans;
}

int getMax(vector<int>& prefix, int idx, vector<string>& words){
    //Remove val that are related to idx (idx-1, idx) and (idx+1, idx)
    int maxi = 0;
    int n = words.size();
    if (n <= 2) return maxi;
    if (idx == 0){
        for (int i=1; i<prefix.size(); i++){
            maxi = max(maxi, prefix[i]);
        }
    }
    else if (idx == n-1){
        for (int i=0; i<prefix.size()-1; i++){
            maxi = max(maxi, prefix[i]);
        }
    }
    else{
        string word1 = words[idx-1];
        string word2 = words[idx+1];
        int newlcp = lcp(word1, word2);
        for (int i=0; i<prefix.size(); i++){
            if (i == idx || i == idx - 1) continue;
            maxi = max(maxi, prefix[i]);
        }
        maxi = max(maxi, newlcp);
    }
    return maxi;
}

vector<int> longestCommonPrefix(vector<string>& words) {
    int n = words.size();
    vector<int> ans;
    vector<int> prefix = adjacentPrefix(words);
    for (int i=0; i<n; i++){
        int val = getMax(prefix, i, words);
        ans.push_back(val);
    }
    return ans;
}


//Optimal

/*
0/ Get LCP of adjacent words
1/ Get the prefix max
2/ Get the suffix max
3/ Then think what can be the answer for each index (if it is not the first
and last index, then compute lcp for w[i-1] and w[i+1] and then find the max b/w
newLcp, max prefix before and after the eliminated word)
*/

int lcp(string word1, string word2){
    int m = min(word1.length(), word2.length());
    int temp = 0;
    int j = 0;
    while (j < m){
        if (word1[j] != word2[j]) break;
        temp++;
        j++;
    }
    return temp;
}

vector<int> longestCommonPrefix(vector<string>& words) {
    int n = words.size();
    if (n == 1) return {0};
    if (n == 2) return {0,0};
    vector<int> ans (n);
    vector<int> adjPrefix (n-1);
    vector<int> prefixMax (n-1);
    vector<int> suffixMax (n-1);
    for (int i=0; i<n-1; i++){
        adjPrefix[i] = lcp(words[i], words[i+1]);
    }
    prefixMax[0] = adjPrefix[0];
    for (int i=1; i<n-1; i++){
        prefixMax[i] = max(prefixMax[i-1], adjPrefix[i]);
    }
    suffixMax[n-2] = adjPrefix[n-2];
    for (int i=n-3; i>=0; i--){
        suffixMax[i] = max(suffixMax[i+1], adjPrefix[i]);
    }
    for (int i=0; i<n; i++){
        //First word is removed (Max LCP from adjPrefix 1 to n-2)
        if (i == 0){
            ans[i] = suffixMax[1];
        }
        //Last word is removed (Max LCP from adjPrefix 0 to n-3)
        else if (i == n-1){
            ans[i] = prefixMax[n-3];
        }
        else{
            int newLcp = lcp(words[i-1], words[i+1]);
            int start = (i - 2 >= 0) ? prefixMax[i - 2] : 0;
            int end = (i + 1 < n - 1) ? suffixMax[i + 1] : 0;
            ans[i] = max(newLcp, max(start, end));
        }
    }
    return ans;
}

//TC - O(N*L)

