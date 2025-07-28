#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char c){
        if (links[c - 'a'] != NULL) return true;
        return false;
    }
    //If the reference is not present, then you add the reference
    void put (char c, Node* newNode){
        links[c - 'a'] = newNode;
    }
    //To go to the next reference
    Node* get(char c){
        return links[c - 'a'];
    }
    //To set flag equal to true, when the word is done
    void setEnd(){
        flag = true;
    }
};

class Trie {
private:
    Node* root;

public:
    //Constructor
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        int n = word.length();
        for (int i=0; i<n; i++){
            if (!temp->containsKey(word[i])){
                temp->put(word[i], new Node ());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        int n = word.length();
        Node* temp = root;
        for (int i=0; i<n; i++){
            if (!temp->containsKey(word[i])) return false;
            temp = temp->get(word[i]);
        }
        if (temp->flag == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        Node* temp = root;
        for (int i=0; i<n; i++){
            if (!temp->containsKey(prefix[i])) return false;
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};