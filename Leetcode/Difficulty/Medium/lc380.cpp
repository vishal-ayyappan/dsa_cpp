#include <bits/stdc++.h>
using namespace std;

//Insert Delete GetRandom O(1)

class RandomizedSet {
private:
    unordered_set<int> s;
public:
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        //If the item is not present
        if (s.find(val) == s.end()){
            s.insert(val);
            return false;
        }
        return true;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end()) return false;
        auto it = s.find(val);
        s.erase(it);
        return true;
    }
    
    int getRandom() {
        int size = s.size();
        auto it = s.begin();
        int random = rand() % size;
        advance(it, random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */