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
You do not have to create new Nodes.
*/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* dummy = new ListNode (-1);
    ListNode* temp = dummy;
    while (temp1 != nullptr && temp2 != nullptr){
        if (temp1->val <= temp2->val){
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        else{
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != nullptr){
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2 != nullptr){
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    return dummy->next;
}

//TC - O(max(n1,n2))
//SC - O(1)