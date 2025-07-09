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
0/ Get to the required node
1/ Have a prev pointer along with it
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr && n == 1) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast != nullptr && n > 0){
        fast = fast->next;
        n--;
    }
    //No Deletion
    if (n != 0  && fast == nullptr) return head;
    while (fast != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if (slow == head) return slow->next;
    if (slow != nullptr) prev->next = slow->next;
    return head;
}

//TC - O(N)
//SC - O(1)