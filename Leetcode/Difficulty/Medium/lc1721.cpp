#include<bits/stdc++.h>
using namespace std;

//Swapping Nodes in a Linked List

struct ListNode {
    int val;
    ListNode *next;
    //Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (k-1 > 0 && fast != nullptr){
        fast = fast->next;
        k--;
    }
    if (fast == nullptr) return head;
    ListNode* node1 = fast;
    while (fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* node2 = slow;
    swap(node1->val, node2->val);
    return head;
}

//TC - O(N)
//SC - O(1)