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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)   //no node or only one
            return head;

        int flag = 0;
        ListNode *p1, *p2, *p3 = NULL, *p4 = NULL;

        p1 = head;
        p2 = head->next;
        head = head->next;

        if (p2->next)
            p3 = p2->next;
        else
            flag = 1;           //!p3 !p4

       // cout<<"flag= "<<flag<<endl;
        if (p3 && p3->next)
            p4 = p3->next;
        else if (p3 && !p3->next)
            flag = 2;          // p3 !p4

       // cout<<"flag= "<<flag<<endl;
        while (p4) {
            p2->next = p1;
            p1->next = p4;
            p1 = p3;
            p2 = p4;
            if (p4->next)
                p3 = p4->next;
            else {
                flag = 1;      //   !p3 !p4
                break;
            }
            if (p4->next->next)
                p4 = p4->next->next;
            else {
                flag = 2;    //  p3 !p4
                break;
            }
        }

        if (flag == 1) {
            p2->next = p1;
            p1->next = NULL;
        }
        else if (flag == 2) {
            p2->next = p1;
            p1->next = p3;
            p3->next = NULL;
        }
        return head;
    }
};

int main () {
    ListNode *head;
    Solution test;

    head = createLinklist();
    printList(head);
    head = test.swapPairs(head);
    printList(head);
    return 0;
}