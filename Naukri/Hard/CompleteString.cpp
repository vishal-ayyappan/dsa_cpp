#include <bits/stdc++.h>
using namespace std;

//Complete String 
// (A string is called a complete string if every prefix of the string is also present in the array).
struct TrieNode{
    TrieNode* links[26];
    bool flag = false;
    //To check if the reference is already contained
    bool containsReference(char ch){
        if (links[ch - 'a'] != nullptr) return true;
        return false;
    }
    //To create a new reference for the character
    void put(char ch, TrieNode* newNode){
        links[ch-'a'] = newNode;
    }   
    //To go to the next character
    TrieNode* get(char ch){
        return links[ch - 'a'];
    }    
};



//You create a Class Trie
class Trie{
    private:
        TrieNode* root;
    public:
        //Constructor
        Trie(){
            root = new TrieNode();
        }

        //Insertion
        void insert(string& word){
            int n = word.length();
            TrieNode* temp = root;
            for (int i=0; i<n; i++){
                if (!temp->containsReference(word[i])){
                    temp->put(word[i], new TrieNode());
                }
                temp = temp->get(word[i]);
            }
            //After the insertion
            temp->flag = true;
        }

        bool checkIfAllprefixPresent(string& word){
            int n = word.length();
            TrieNode* temp = root;
            for (int i=0; i<n; i++){
                if (!temp->containsReference(word[i])) return false;
                temp = temp->get(word[i]);
                if (temp->flag == false) return false;
            }
            return true;
        }

};

string completeString(int n, vector<string> &a){
    Trie myTrie = Trie();
    //Insert all the words in the trie.
    for (int i=0; i<n; i++){
        myTrie.insert(a[i]);
    }
    //You have to check for the longest string
    string res = "";
    int maxLen = 0;
    for (int i=0; i<n; i++){
        if (myTrie.checkIfAllprefixPresent(a[i])){
            if (a[i].length() > maxLen){
                maxLen = a[i].length();
                res = a[i];
            } 
            else if (a[i].length() == maxLen){
                if (a[i] < res) res = a[i];
            }
        }
    }
    if (res == "") return "None";
    return res;
}