//
// Created by Will on 12/13/15.
//

#include <iostream>
#include "linkList.h"
using namespace std;
/*                                      翻转整个链表
ListNode* reverseList (ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode *p1, *p2, *p3;
    p1 = NULL;
    p2 = head;
    p3 = head->next;

    while (p3) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    return p2;

}
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         if (m == n)
             return head;
        ListNode *p, *pre, *back, *p1, *p2, *p3, *start, *end;
      //  bool flag_head = false, flag_tail = false;

        pre = NULL;
        p1 = NULL;
        p = head;
        if (m == 1)
            start = head;
        for (int i = 1; i < n; i++) {
            pre = p;
            p = p->next;
            if (m - 1 == i) {
                p1 = pre;
                start = p;
            }
        }
        pre = p1;
        end = p;
        back = end->next;

        p1 = back;
        p2 = start;
        p3 = start->next;
        while (p3 != back) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        if (m == 1)
            return p2;
        pre->next = end;
        return head;
    }

};



int main () {
    Solution test;
    int n, m;
    ListNode *head;
    head = creatSimpleList(10);
    printList (head);
    cin>>n>>m;
    head = test.reverseBetween (head, n, m);
    printList (head);
    return 0;


}