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
        struct ListNode *head1,*p,*p1,*p2;

        if (head==NULL)
            return NULL;

        head1=p1=p2=(struct ListNode*) malloc (sizeof(struct ListNode));
        head1->val=head->val;
        p=head;
        while (p!=NULL) {
            if (p->val!=p1->val){
                p2=(struct ListNode*) malloc (sizeof(struct ListNode));
                p2->val=p->val;
                p1->next=p2;
                p1=p2;
            }
            p=p->next;
        }
        p2->next=NULL;
        return head1;


    }
};

int main() {
    Solution test;
    struct ListNode *head;

    head=createLinklist();
    printList(head);
    head=test.deleteDuplicates(head);
    printList(head);
    return 0;


}