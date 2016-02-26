//
// Created by Will on 12/11/15.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (!headA || !headB)
            return NULL;

        int a_len = 0, b_len = 0;                                      //get len
        for (ListNode *la = headA; la; la = la->next) a_len++;
        for (ListNode *lb = headB; lb; lb = lb->next) b_len++;

        ListNode *la = (a_len > b_len) ? headA : headB;
        ListNode *lb = (a_len > b_len) ? headB : headA;
        int d = abs(a_len - b_len);
        for(int i = 0; i < d; i++)
            la = la->next;                                           //align

        while (la && lb) {
            if (la == lb)
                return la;
            la = la->next;
            lb = lb->next;
        }

        return NULL;
    }
};
