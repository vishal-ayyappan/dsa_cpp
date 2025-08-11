#include <bits/stdc++.h>
using namespace std;

//Word Ladder II

//Each word will have the corresponding level in which it has been attaines
unordered_map<string, int> getEndPoints(string beginWord, string endWord, vector<string>& wordList, unordered_map<string, int> mpp){
    int n = wordList.size();
    int m = beginWord.length();
    vector<bool> visited (n, false);
    unordered_map<string, int> wordEnd;
    queue<string> q;
    q.push(beginWord);
    if (mpp.find(beginWord) != mpp.end()) visited[mpp[beginWord]] = true;
    int level = 0;
    while (!q.empty()){
        int n = q.size();
        for (int i=0; i<n; i++){
            string word = q.front();
            q.pop();
            wordEnd[word] = level;
            for (int j=0; j<m; j++){
                char original = word[j];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[j] = ch;
                    if (mpp.find(word) != mpp.end() && !visited[mpp[word]]){
                        q.push(word);
                        visited[mpp[word]] = true;
                    }
                }
                word[j] = original;
            }
        }
        level++;
    }
    return wordEnd;
}

//Do the DFS with constraints
void getAllCombinations(unordered_map<string,int>& word, vector<string>& ds, vector<vector<string>>& ans, string beginWord){
    if (ds.back() == beginWord){
        reverse(ds.begin(), ds.end());
        ans.push_back(ds);
        reverse(ds.begin(), ds.end());
        return;
    }
    string currWord = ds.back();
    int steps = word[currWord];
    for (int i=0; i<currWord.length(); i++){
        char og = currWord[i];
        for (char ch='a'; ch <= 'z'; ch++){
            currWord[i] = ch;
            //If the word is not visited and is part of the levels and if the level is 1 below the current level.
            if (word.find(currWord) != word.end() && word[currWord] == steps-1){
                ds.push_back(currWord);
                getAllCombinations(word, ds, ans, beginWord);
                ds.pop_back();
            }
        }
        currWord[i] = og;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //Get the minimum number of transformations required
    int n = wordList.size();
    unordered_map<string, int> mpp;
    for (int i=0; i<n; i++){
        mpp[wordList[i]] = i;
    }
    unordered_map<string, int> word = getEndPoints(beginWord, endWord, wordList, mpp);
    vector<vector<string>> ans;
    vector<bool> onLevelVisited (n, false);
    if (mpp.find(endWord) != mpp.end()){
        int steps = mpp[endWord];
        vector<string> ds;
        ds.push_back(endWord);
        vector<bool> onLevelVisited (n, false);
        getAllCombinations(word, ds, ans, beginWord);
        return ans;
    }
    return ans;
}