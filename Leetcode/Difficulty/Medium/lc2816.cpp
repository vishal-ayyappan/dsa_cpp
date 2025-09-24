#include <bits/stdc++.h>
using namespace std;

//Double a Number Represented as a Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    //Reversing the Linked List
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    //Doubling the numbers
    void operationsLL(ListNode* head){
        ListNode* temp = head;
        int carry = 0;
        while (temp->next != nullptr){
            int value = temp->val;
            int total = 2*value + carry;
            carry = total/10;
            int digit = total%10;
            temp->val = digit;
            temp = temp->next;
        }
        int value = temp->val;
        int total = 2*value + carry;
        carry = total/10;
        temp->val = total%10;
        while (carry != 0){
            int digit = carry%10;
            ListNode* newNode = new ListNode(digit);
            carry /= 10;
            temp->next = newNode;
            temp = temp->next;
        }
    }
public:
    ListNode* doubleIt(ListNode* head) {
        //Reverse the LL
        ListNode* temp = reverseLL(head);
        //Do the operations
        operationsLL(temp);
        //Reverse again
        ListNode* newHead = reverseLL(temp);
        return newHead;
    }
};