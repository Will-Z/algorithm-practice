//
// Created by Will on 12/13/15.
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
    ListNode* rotateRight(ListNode* head, int k) {
        int num = 0;
        ListNode *p = head, *p1, *p2, *tail;
        if (!p || !p->next)
            return head;
        while (p) {
            tail = p;
            p = p->next;
            num++;
        }
        k = k % num;
        if (k == 0)
            return head;
        tail->next = head;
        p1 = p2 = head;
        for (int i = 1; i <= num - k; i++)
        {
            p1 = p2;
            p2 = p2->next;
        }
        p1->next =NULL;
        return p2;

    }
};

int main () {
    Solution test;
    ListNode *head;

    head = creatSimpleList (0);
    printList (head);
    head = test.rotateRight (head, 12);
    printList (head);
    return 0;
}