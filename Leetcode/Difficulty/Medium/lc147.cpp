#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLL(ListNode* head){
    if (head == nullptr) return;
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


void correctOrder(ListNode* head){
    if (head == nullptr) return;
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while (temp != nullptr){
        if (prev != nullptr && temp->val > prev->val){
            swap(prev->val, temp->val);
        }
        prev = temp;
        temp = temp->next;
    }
}

void func(ListNode* head, ListNode* temp){
    if (head == temp) return;
    ListNode* nextNode = temp->next;
    temp->next = nullptr;
    ListNode* newHead = reverseLL(head);
    // The node must be in descending order
    correctOrder(newHead);
    head = reverseLL(newHead);
    newHead->next = nextNode;
}

ListNode* insertionSortList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr){
        func(head, temp);
        temp = temp->next;
    }
    return head;
}

//TC - O(N*3N)
//SC - O(1)