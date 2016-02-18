//
// Created by Will on 12/18/15.
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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;

        ListNode *head1, *head2, *p, *p1, *p2;
        head1 = NULL;
        head2 = NULL;
        p = head;

        while (p) {
            if (!head1 && p->val < x)
                head1 = p1 = p;
            else if (!head2 && p->val >= x)
                head2 = p2 = p;
            else {
                if (p->val < x){
                    p1->next = p;
                    p1 = p1->next;
                }
                else {
                    p2->next = p;
                    p2 = p2->next;
                }
            }
            p = p->next;
        }
        if (head1 && head2) {
            p1->next = head2;
            p2->next = NULL;
            return head1;
        }
        else if (head1 && !head2) {
            p1->next = NULL;
            return head1;
        }
        else if (!head1 && head2) {
            p2->next = NULL;
            return head2;
        }


    }
};

int main() {
    Solution test;
    ListNode *head;
    head = createLinklist();
    printList(head);
    head = test.partition(head, 3);
    printList(head);
    return 0;
}