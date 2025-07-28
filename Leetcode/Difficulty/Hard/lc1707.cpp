#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* links[2];
    //Check if the bit exists. (It should have a reference)
    bool containsReference(int bit){
        if (links[bit] != nullptr) return true;
        return false;
    }
    //Inserting the character and creating a reference for it.
    void put(int bit, TrieNode* newNode){
        links[bit] = newNode;
    }
    //Going to the next node
    TrieNode* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        //Insertion of the bit in the trie
        void insert(int num){
            TrieNode* temp = root;
            for (int i=31; i>=0; i--){
                int bit = (num>>i) & 1;
                //If the bit does not exists i.e. if it does not contain reference
                if (!temp->containsReference(bit)){
                    temp->put(bit, new TrieNode());
                }
                temp = temp->get(bit);
            }
        }
        //Get the maximum xor
        int getMax(int num){
            TrieNode* temp = root;
            int maxXor = 0;
            for (int i=31; i>=0; i--){
                //Check if the target number bit is set or not
                int bit = (num>>i) & 1;
                int toggleBit = bit ^ 1;
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

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = queries.size();
    sort(nums.begin(), nums.end());
    vector<int> ans (n);
    int m = nums.size();
    Trie* myTrie = new Trie();
    //We deal with offline queries (Queries that are not in order)
    vector<tuple<int, int, int>> v; //for storing queries
    for (int i=0; i<n; i++){
        int key1 = queries[i][0];
        int key2 = queries[i][1];
        int key3 = i;
        auto tup = make_tuple(key1, key2, key3);
        v.push_back(tup);
    }
    sort(v.begin(), v.end(), [](tuple<int, int, int>& t1, tuple<int, int, int>& t2){
        //Sort according to the nums mi
        return get<1>(t1) < get<1>(t2);
    });
    int j = 0;
    for (int i=0; i<n; i++){
        auto tup = v[i];
        //Get the first element, that is the target
        int x = get<0>(tup);
        int maxi = get<1>(tup);
        int idx = get<2>(tup);
        //Add all the elements in the trie, that is less than maxi
        while (j < m  && nums[j] <= maxi){
            int num = nums[j];
            myTrie->insert(num);
            j++;
        }
        if (j == 0) ans[idx] = -1;
        else{
            //Get the maximum xor, with the inserted elements in the trie
            ans[idx] = myTrie->getMax(x);
        }
    }
    return ans; 
}