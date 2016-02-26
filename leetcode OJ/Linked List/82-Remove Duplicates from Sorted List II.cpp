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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *p, *p1, *p2, *pre;

        p = pre = (ListNode *) malloc (sizeof(ListNode));
        p1 = p2 = head;
        int num = 0;

        while(p1) {
            //cout<<++num<<endl;
            while (p2->next && p2->val == p2->next->val)
                p2 = p2->next;
            if (p1 == p2) {               //distinct  node
                p->next = p1;
                p = p->next;
               // cout<<"distinct node  "<<p->val<<endl;
                p1 = p2 = p1->next;
            }
            else {                        //duplicate node
              //  cout<<"duplicate node"<<p2->val<<endl;
                p1 = p2 = p2->next;
            }

        }
        p->next = NULL;



        return pre->next;

    }
};

int main() {
    Solution test;
    ListNode *head;
    head = createLinklist();
    printList(head);
    head = test.deleteDuplicates(head);
    printList(head);
    return 0;
}