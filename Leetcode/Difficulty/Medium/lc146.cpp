#include <bits/stdc++.h>
using namespace std;

//LRU Cache

//DLL
struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    //Constructor
    Node(int key_, int value_){
        key = key_;
        value = value_;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int n;
    unordered_map<int, Node*> mpp;
    Node* tail;
    Node* head;

    //Delete Node
    void deleteNode(Node* temp){
        Node* front = temp->next;
        Node* back = temp->prev;
        //Connect the front and back
        front->prev = back;
        back->next = front;
    }

    //Insert after Head
    void insertAfterHead(Node* temp){
        Node* afterHead = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = afterHead;
        afterHead->prev = temp;
    }
public:
    LRUCache(int capacity) {
        n = capacity;
        //Clear the map
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1); 
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //if key does not exist in map
        if (mpp.find(key) == mpp.end()) return -1;
        Node* temp = mpp[key];
        deleteNode(temp);
        insertAfterHead(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        //If key is present
        if (mpp.find(key) != mpp.end()){
            //Update in the map
            Node* temp = mpp[key];
            temp->value = value;
            deleteNode(temp);
            insertAfterHead(temp);
        }
        else{
            //if capacity exceeds
            if (mpp.size() == n){
                //Delete the least recent node
                Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete(lru);  
            }
            //Add the node
            Node* temp = new Node(key, value);
            mpp[key] = temp;
            insertAfterHead(temp);
        }
    }
};