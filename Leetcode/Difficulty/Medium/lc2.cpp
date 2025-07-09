#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    //Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
0/ Sum up each level of both the nodes one by one and keep a carry
1/ At the end if the carry is there, attach it at the end
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //Dummy Node
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    int carry = 0;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    while (temp1 != nullptr && temp2 != nullptr){
        int sum = temp1->val + temp2->val + carry;
        carry = sum/10;
        int value = sum%10;
        ListNode* newNode = new ListNode(value);
        temp->next = newNode;
        temp = temp->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != nullptr){
        int sum = temp1->val + carry;
        carry = sum/10;
        int value = sum%10;
        ListNode* newNode = new ListNode(value);
        temp->next = newNode;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2 != nullptr){
        int sum = temp2->val + carry;
        carry = sum/10;
        int value = sum%10;
        ListNode* newNode = new ListNode(value);
        temp->next = newNode;
        temp = temp->next;
        temp2 = temp2->next;
    }
    if (carry != 0){
        ListNode* newNode = new ListNode(carry);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}

//TC - O(min(len(l1),len(l2)) + max(len(l1),len(l2)) - min(len(l1),len(l2)))
//SC - Same as above