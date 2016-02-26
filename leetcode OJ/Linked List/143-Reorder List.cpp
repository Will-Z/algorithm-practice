//
// Created by Will on 12/17/15.
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
    ListNode *reverseList(ListNode *head) {
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode *fast, *slow, *head1, *head2, *p1, *p2, *p11, *p22;
        slow = head;
        fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        head1 = head;
        head2 = slow->next;
        slow->next = NULL;
        head2 = reverseList(head2);

        p1 = head1;
        p2 = head2;
/*
        printList(p1);
        printList(p2);
        cout<<"in this"<<endl;
*/
        while (p1 && p2) {
          //  cout<<p1->val<<"   "<<p2->val<<endl;
            p11 = p1->next;
            p22 = p2->next;
            p1->next = head2;
            head1 = p11;
            p2->next = head1;
            head2 = p22;
            p1 = p11;
            p2 = p22;

        }



        if (p1)
            p1->next = NULL;



    }
};

int main() {
    Solution test;
    ListNode *head;
    head = creatSimpleList(10);
    printList(head);
    test.reorderList(head);
   // head = test.reverseList(head);
    printList(head);
    return 0;

}