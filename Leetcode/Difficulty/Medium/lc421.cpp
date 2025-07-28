#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* links[2];
    //Check if the bit contains a reference
    bool containsReference(int bit){
        if (links[bit] != nullptr) return true;
        return false;
    }
    //Inserting a bit
    void put(int bit, TrieNode* newNode){
        links[bit] = newNode;
    }
    //Going to the next bit
    TrieNode* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            //Declare the root node
            root = new TrieNode();
        }
        //Insertion of the bit values of the number
        void insert(int num){
            TrieNode* temp = root;
            for (int i=31; i>=0; i--){
                //Check if the ith bit of the number is set or not
                int bit = (num>>i) & 1;
                if (!temp->containsReference(bit)){
                    //Insert the bit and create a reference for it
                    temp->put(bit, new TrieNode());
                }
                temp = temp->get(bit);
            } 
        }
        //Get the maximum xor value
        int getMax(int num){
            int maxXor = 0;
            TrieNode* temp = root;
            for (int i=31; i>=0; i--){
                //Check if the bit is set or not
                int bit = (num>>i) & 1;
                int toggleBit = bit^1;
                //Check if the toggle exist (then move along there)
                if (temp->containsReference(toggleBit)){
                    maxXor = maxXor | (1<<i);
                    temp = temp->get(toggleBit);
                }
                else{
                    temp = temp->get(bit);
                }
            }
            return maxXor;
        }

};

int findMaximumXOR(vector<int>& nums) {
    //Insert all the elements of the array in the trie and do the checking one by one
    int n = nums.size();
    Trie* myTrie = new Trie();
    //Insert all the numbers in the trie.
    for (int i=0; i<n; i++){
        myTrie->insert(nums[i]);
    }
    //Check for each number
    int maxXor = 0;
    for (int i=0; i<n; i++){
        //Find the maximum xor
        maxXor = max(maxXor, myTrie->getMax(nums[i]));
    }
    return maxXor;
}