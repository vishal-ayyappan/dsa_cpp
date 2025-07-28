#include <bits/stdc++.h>
using namespace std;

//Count Distinct Substrings

struct TrieNode{
    TrieNode* links[26];
    bool flag = false;
    //Checking the existing of the character
    bool containsReference(char ch){
        if (links[ch - 'a'] != nullptr) return true;
        return false;
    }
    TrieNode* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, TrieNode* newNode){
        links[ch - 'a'] = newNode;
    }
};


class Trie{
    private:
        TrieNode* root;
    public:
        //Constructor
        Trie(){
            root = new TrieNode();
        }
        bool insert(string& word){
            int n = word.length();
            TrieNode* temp = root;
            for (int i=0; i<n; i++){
                if (!temp->containsReference(word[i])){
                    //Put the word in
                    temp->put(word[i], new TrieNode());
                }
                //Go to the next character
                temp = temp->get(word[i]);
            }
            //If the word is already present
            if (temp->flag) return false;
            temp->flag = true;
            return true;
        }

};


int countDistinctSubstrings(string &s){
    //Insert all the words in the trie. If it exists, do not increase the count.
    int n = s.length();
    Trie* myTrie = new Trie();
    int count = 0;
    for (int i=0; i<n; i++){
        string res;
        for (int j=i; j<n; j++){
            res.push_back(s[j]);
            //If it is already present, do not count it.
            if (myTrie->insert(res)) count++;
        }
    }
    return count+1; //Including the empty substring
}