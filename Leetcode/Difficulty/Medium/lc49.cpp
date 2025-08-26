#include <bits/stdc++.h>
using namespace std;

//Group anagrams

// 1/ Put every word in the map
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<int, string> mpp;
    int n = strs.size();
    for (int i=0; i<n; i++){
        mpp[i] = strs[i];
    }
    for (int i=0; i<n; i++){
        sort(strs[i].begin(), strs[i].end());
    }
    unordered_map<string, vector<string>> log;
    for (int i=0; i<n; i++){
        string s = strs[i];
        log[s].push_back(mpp[i]);
    }
    vector<vector<string>> ans;
    for (auto& it : log){
        ans.push_back(it.second);
    }
    return ans;
}

//Another approach (Without sorting)
string generate_str(string& temp){
    vector<int> freq (26, 0);
    int n = temp.length();
    for (int i=0; i<n; i++){
        freq[temp[i]-'a']++;
    }
    //Get the string
    string newWord;
    for (int i=0; i<26; i++){
        if (freq[i] > 0){
            string word = string(freq[i], i+'a');
            newWord += word;
        }
    }
    return newWord;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    unordered_map<string, vector<string>> mpp;
    for (int i=0; i<n; i++){
        string temp = strs[i];
        string newWord = generate_str(temp);
        mpp[newWord].push_back(temp);
    }
    vector<vector<string>> ans;
    for (auto& it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
