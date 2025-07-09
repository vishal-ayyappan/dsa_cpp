#include<bits/stdc++.h>
using namespace std;

// Reverse the nodes in K groups

struct ListNode {
    int val;
    ListNode *next;
    //Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLL (ListNode* head){
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while (temp != nullptr){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* front = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr){
        int p = k;
        while (fast != nullptr && p-1 > 0){
            fast = fast->next;
            p--;
        }
        if (fast == nullptr) break;
        ListNode* attach = fast->next;
        fast->next = nullptr;
        ListNode* revNode = reverseLL(slow);
        if (front == nullptr) head = revNode;
        else front->next = revNode;
        slow->next = attach;
        front = slow;
        slow = attach;
        fast = attach;
    }
    return head;
}

//TC - O(N)
//SC - O(1)