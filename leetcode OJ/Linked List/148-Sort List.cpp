//
// Created by Will on 12/12/15.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <cstdlib>
#include "linkList.h"
using namespace std;

class Solution {                                      //merge sort with linklist
public:
    ListNode* merge (ListNode *left, ListNode *right) {
        ListNode *head = (ListNode *) malloc (sizeof (ListNode));
        ListNode *p;
        p = head;
        while (left && right) {
            if (left->val <= right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                    p->next = right;
                    right = right->next;
                }
            p = p->next;
        }
        if (left)
            p->next = left;
        if (right)
            p->next = right;
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow, *fast, *left, *right;
        slow = head;
        fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        right = sortList (slow->next);
        slow->next = NULL;
        left = sortList (head);
        return merge (left, right);


    }
};

int main () {
    Solution test;
    ListNode *head;

    head = createLinklist ();
    printList (head);
    head = test.sortList (head);
    printList (head);
    return 0;
}










