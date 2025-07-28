#include <bits/stdc++.h>
using namespace std;

//Maximum XOR.

struct TrieNode{
    //Either a 0 or a 1
    TrieNode* links[2];
    //Check if the bit contains reference, if it doesnt, then the bit does not exist and we have to add em
    bool containsReference(int bit){
        if (links[bit] != nullptr) return true;
        return false;
    }
    //Inserting the bit
    void put(int bit, TrieNode* newNode){
        links[bit] = newNode;
    }
    //Go to the next bit
    TrieNode* get (int bit){
        return links[bit];
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
        //Insertion
        void insert(int num){
            TrieNode* temp = root;
            //Put the bit form of the number
            for (int i=31; i>=0; i--){
                //To check if the ith bit is set or not
                int bit = (num>>i) & 1;
                //If the reference does not exist
                if (!temp->containsReference(bit)){
                    //Insert it.
                    temp->put(bit, new TrieNode());
                }
                temp = temp->get(bit);
            }
        }
        //Get the maximum XOR of the number with the array
        int getMax(int num){
            int maxXor = 0;
            TrieNode* temp = root;
            for (int i=31; i>=0; i--){
                int bit = (num>>i) & 1;
                //For max xor, you have to see if bit^1 is present in the trie.
                int toggleBit = bit^1;
                if (temp->containsReference(toggleBit)){
                    maxXor |=  (1<<i);
                    temp = temp->get(toggleBit);
                }
                else{
                    temp = temp->get(bit);
                }
            }
            return maxXor;
        }
        

};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    Trie* myTrie = new Trie();
    //Insert all the numbers of arr1 in the trie, in terms of bits.
    for (int i=0; i<n; i++){
        myTrie->insert(arr1[i]);
    }
    int maxXor = 0;
    for (int i=0; i<m; i++){
        int num = arr2[i];
        maxXor = max(maxXor, myTrie->getMax(num));
    }
    return maxXor;
}