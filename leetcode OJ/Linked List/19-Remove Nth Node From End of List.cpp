//
// Created by Will on 12/4/15.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "linkList.h"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tot=0;
        ListNode *p,*q;
        int i=0;
        ListNode **a= new ListNode* [10000000];

        p=head;
        while (p!=NULL) {
            tot++;
            a[tot]=p;                 // a[i]指向第i个元素  a[0] 不做使用
            p=p->next;
        }

        if (tot==1 || head==NULL)        //针对仅有一个元素或者无元素的情况
            return NULL;

        if(tot-n+1==1) {//要删除的元素是第一个元素
         //   cout<<"this is branch 1"<<endl;
            return head->next;
        }
        //cout<<"this is branch two"<<endl;
        p=a[tot-n+1];   //p指向要删除的元素
        q=a[tot-n];      //q指向要删除元素的前一个元素
        q->next=p->next;

        delete p;

        return head;

    }
};

int main() {
    int i=0;
    ListNode **a= new ListNode* [10000000];
    ListNode *head,*p;
    Solution question;

    head=creatSimpleList(10);
    printList(head);
    cout<<endl;

    head=question.removeNthFromEnd(head,1);
    printList (head);


    return 0;
}