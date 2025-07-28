#include <bits/stdc++.h>
using namespace std;


//The Data structure for storing
struct TrieNode{
    TrieNode *links[26];
    bool flag = false;
    //Create a method the check if it contains the reference
    bool containsReference(char ch){
        if (links[ch - 'a'] != nullptr) return true;
        return false;
    }
    //To place the character and creating a reference node
    void put(char ch, TrieNode* newNode){
        //Create a reference for the character
        links[ch - 'a'] = newNode;
    }
    //To go to the next node
    TrieNode* get(char ch){
        return links[ch - 'a'];
    }
    //To mark last characters reference of each word to true. 
    void setEnd(){
        flag = true;
    }
};

class Trie {
private:
    TrieNode* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        TrieNode* temp = root;
        //Insert each character and for each character create a reference for it.
        for (int i=0; i<n; i++){
            if (!temp->containsReference(word[i])){
                //Put the character in and create a reference for that.
                temp->put(word[i], new TrieNode());
            }
            //Go to the next TrieNode
            temp = temp->get(word[i]);
        }
        //Once the word is traversed, change the flag to true at the last characters' reference node
        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        TrieNode* temp = root;
        for (int i=0; i<n; i++){
            if (!temp->containsReference(word[i])) return false;
            //Go to its reference
            temp = temp->get(word[i]);
        }
        //The last characters' reference should be marked as true, for the word to be completeds
        if (temp->flag == true) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode* temp = root;
        for (int i=0; i<n; i++){
            if (!temp->containsReference(prefix[i])) return false;
            //Go to its reference
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};