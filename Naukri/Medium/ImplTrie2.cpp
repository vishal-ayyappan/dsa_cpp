#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* links[26];
    int endwith = 0;
    //startswith of a node, tells how many words are the there that contain the parent letter
    int countParent = 0;
    //To check if the reference exists or not
    bool containsReference(char ch){
        if (links[ch - 'a'] == nullptr) return false;
        return true;
    }
    //To create a reference for the character
    void put(char ch, TrieNode* newNode){
        links[ch - 'a'] = newNode;
    }
    //Go to the next character
    TrieNode* get(char ch){
        return links[ch - 'a'];
    }
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            //When the object is called, you create a new root.
            root = new TrieNode();
        }

        void insert(string &word){
            int n = word.length();
            TrieNode* temp = root;
            for (int i=0; i<n; i++){
                //If the reference does not exist
                if (!temp->containsReference(word[i])){
                    //Create a reference for that character.
                    temp->put(word[i], new TrieNode());
                }
                //Go to the next character (to check its reference)
                temp = temp->get(word[i]);
                temp->countParent += 1;
            }
            temp->endwith += 1;
        }

        int countWordsEqualTo(string &word){
            int n = word.length();
            TrieNode* temp = root;
            for (int i=0; i<n; i++){
                if (!temp->containsReference(word[i])) return 0;
                temp = temp->get(word[i]);
            }
            //endWith tells us the no of times word is present.
            return temp->endwith;
        }

        int countWordsStartingWith(string &word){
            int n = word.length();
            TrieNode* temp = root;
            for (int i=0; i<n; i++){
                if (!temp->containsReference(word[i])) return 0;
                temp = temp->get(word[i]);
            }
            //No of wrods starting with 'word'
            return temp->countParent;
        }

        void erase(string &word){
            //Given that the word always exists in the trie data structure
            int n = word.length();
            TrieNode* temp = root;
            for (int i=0; i<n; i++){
                temp = temp->get(word[i]);
                temp->countParent--;
            }
            temp->endwith--;
        }
};
