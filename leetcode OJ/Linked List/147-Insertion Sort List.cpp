//
// Created by Will on 12/28/15.
//

#include <iostream>
#include "linkList.h"
using namespace std;


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *pre, *p, *pp, *insertNode, *insertNodePre, *pPre, *ppFollow, *insertNodeFollow; //pp作为有序和无序的两段的分界 也相当于外层循环的指针
        int min;
        pre = pp = (ListNode *) malloc (sizeof(ListNode));
        pre->next = head;

        while (pp->next) {
            p = pp;
            min = 2147483647;
          //  cout<<"p->val  "<<p->next->val<<endl;
            while(p->next) {
                pPre = p;
                p = p->next;
                if (p->val <= min) {     //use "<="  cause there is a set of input [2147483647,2147483646]
                    min = p->val;
                    insertNode = p;
                    insertNodePre = pPre;
                }
            }
           // cout<<"insertNode=    "<<insertNode->val<<endl;

            if (pp->next != insertNode) {
                ppFollow = pp->next;
                insertNodeFollow = insertNode->next;
                pp->next = insertNode;
                insertNode->next = ppFollow;

                insertNodePre->next = insertNodeFollow;


            }
            pp = pp->next;
        }

        return pre->next;
    }
};

int main() {
    Solution test;
    ListNode *head;
    head = createLinklist();
    printList(head);
    head = test.insertionSortList(head);
    printList(head);
  //  cout<<(numeric_limits<int>::max)();


    return 0;


}