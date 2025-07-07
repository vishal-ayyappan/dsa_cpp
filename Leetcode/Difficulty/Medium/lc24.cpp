#include<bits/stdc++.h>
using namespace std;

//Swap nodes in Pairs

struct ListNode {
    int val;
    ListNode *next;
    //Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Reverse the 2 nodes you go

ListNode* reverseLL(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while (temp != nullptr){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* temp = head;
    ListNode* front = nullptr;
    while (temp != nullptr && temp->next != nullptr){
        ListNode* attach = temp->next->next;
        temp->next->next = nullptr;
        ListNode* revNode = reverseLL(temp);
        if (front == nullptr) head = revNode;
        else front->next = revNode;
        front = temp;
        temp->next = attach;
        temp = attach;
    }
    return head;
}

//TC - O(N)
//SC - O(1)