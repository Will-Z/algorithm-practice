//
// Created by Will on 12/10/15.
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
#include "linkList.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head,*p1,*p2;

        if(l1 != NULL && l2 == NULL)
            return l1;
        else if(l1 == NULL && l2 != NULL)
            return l2;
        else if (l1 == NULL && l2 == NULL)
            return NULL;

        head=p1=p2=(ListNode*) malloc (sizeof(ListNode));
        if (l1->val<l2->val) {
            head->val = l1->val;
            l1 = l1->next;
        }
        else {
            head->val = l2->val;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL) {
            p2=(ListNode*) malloc (sizeof(ListNode));
            if (l1->val < l2->val) {
                p2->val = l1->val;
                l1 = l1->next;
            }
            else {
                p2->val = l2->val;
                l2 = l2->next;
            }
            p1->next = p2;
            p1 = p2;
        }
        if (l1 != NULL)
            p2->next = l1;
        else
            p2->next = l2;

        return head;
    }
};

int main() {
    Solution test;
    ListNode *l1,*l2,*head;
    l1=createLinklist();
    l2=createLinklist();
    head=test.mergeTwoLists(l1,l2);
    printList(head);
    return 0;
}