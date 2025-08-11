#include <bits/stdc++.h>
using namespace std;

//Word Ladder 1

//Level Order BFS Traversal

int getLength(string beginWord, string endWord, int n, unordered_map<string, int>& mpp){
    int wordLength = beginWord.length();
    vector<bool> visited (n, false);
    queue<string> q;
    q.push(beginWord);
    if (mpp.find(beginWord) != mpp.end()) visited[mpp[beginWord]] = true;
    int count = 1;
    while (!q.empty()){
        int n = q.size();
        for (int i=0; i<n; i++){
            string word = q.front();
            q.pop();
            for (int j=0; j<wordLength; j++){
                char ch = word[j];
                for (int k=0; k<26; k++){
                    word[j] = char('a'+k);
                    //If the string exists
                    if (mpp.find(word) != mpp.end() && !visited[mpp[word]]){
                        if (word == endWord) return count+1;
                        q.push(word);
                        visited[mpp[word]] = true;
                    }
                }
                word[j] = ch;
            }
        }
        count++;
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //Store the string in the hashmap with value as the index
    unordered_map<string, int> mpp;
    int n = wordList.size();
    for (int i=0; i<n; i++){
        mpp[wordList[i]] = i;
    }
    return getLength(beginWord, endWord, n, mpp);
}