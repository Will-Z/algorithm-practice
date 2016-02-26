//
// Created by Will on 12/6/15.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre,*p1,*p2,*p3;

        if (head==NULL) {
            cout<<"this is branch1"<<endl;
            return head;
        }
        cout<<"this is branch2"<<endl;

        pre=(ListNode*) malloc (sizeof( ListNode));
        pre->next=head;
        p1=pre;
        p2=head;
        while(p2!=NULL)
        {
            if (p2->val==val){
                p3=p2;
                p2=p2->next;
                p1->next=p2;
                delete p3;

            }
            else{
                p1=p2;
                p2=p2->next;
            }
        }
        return pre->next;

    }
};

int main () {
    Solution test;
    ListNode *head;

    //head=creatSimpleList(10);
    head=createLinklist();
    printList(head);

    head=test.removeElements(head,1);
    printList(head);

    return 0;

}
