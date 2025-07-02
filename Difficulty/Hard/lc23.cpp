#include<bits/stdc++.h>
using namespace std;

// Merge k Sorted Lists

struct ListNode {
    int val;
    ListNode *next;
    //Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
0/ Use a heap to store each element from all the list
1/ Get the minimum out of it and place the next node of the same list in the heap
*/

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if (k == 0) return nullptr;
    //Min Heap Implementation
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    int i = 0;
    for (int i=0; i<k; i++){
        if (lists[i] != nullptr) pq.push({lists[i]->val, lists[i]});
    }
    ListNode* dummy = new ListNode (-1);
    ListNode* temp = dummy;
    while (!pq.empty()){
        auto item = pq.top();
        pq.pop();
        ListNode* tempNode = item.second;
        if (tempNode->next != nullptr) pq.push({tempNode->next->val, tempNode->next});
        temp->next = tempNode;
        temp = tempNode;
    } 
    return dummy->next;
}

//TC - O(K*N)
//SC - O(K)