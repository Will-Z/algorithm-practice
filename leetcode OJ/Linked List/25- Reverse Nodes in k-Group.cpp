//
// Created by Will on 1/13/16.
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
    void reverseList (ListNode *l1, ListNode *l2) {
        ListNode *pre, *t1, *t2, *t3;

        t1 = NULL;
        t2 = l1;
        t3 = l1->next;
        while (t2 != l2) {
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t3->next;
        }
        t2->next = t1;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head || !head->next)
            return head;

        int num, thisGroupDown, flag, jd;
        ListNode *p, *p1, *p2, *pp1, *pp2, *rhead;

        p = p1 = head;
        num = 1;
        thisGroupDown = 0;
        flag = 0;
        jd = 0;


        while (p) {
            p = p->next;
            num++;
            if (num == k && p) {
                jd = 1;
                p2 = p;
                pp2 = p2->next;
                reverseList(p1, p2);
                if (!thisGroupDown) {
                    thisGroupDown = 1;
                    pp1 = p1;
                    rhead = p2;
                } else {
                    pp1->next = p2;
                    pp1 = p1;
                }

                if (pp2) {
                    p = p1 = pp2;
                    num = 1;
                } else {
                    p = pp2;
                    p1->next = NULL;
                    flag = 1;
                }



            }
        }
        if (jd && !flag)
            pp1->next = p1;
        else if (!jd)
            return head;

        return rhead;


    }
};

int main() {
    Solution test;
    ListNode *head;

    head = createLinklist();
    printList(head);


    head = test.reverseKGroup(head, 2);
    printList(head);

    return 0;








}