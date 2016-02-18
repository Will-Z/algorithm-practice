//
// Created by Will on 12/3/15.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
  };

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p1,*p2,*p3;
    p1=NULL;
    p2=head;
    if (head==NULL) return head;
    p3=head->next;

    while (1){
        p2->next=p1;
        p1=p2; p2=p3;
        if (p2==NULL)
            break;
        p3=p3->next;
    }
    return p1;
}


int main() {
    int i;
    struct ListNode *head, *p, *q, *reversed;


    //create single linklist;
    head=q=(struct ListNode *) malloc (sizeof(ListNode));
    head->data=1;
    //head->next=NULL;
/*    for (i=2;i<=10;i++){
        p=(struct ListNode *) malloc (sizeof(ListNode));
        p->data=i;
        q->next=p;
        q=p;
    }
    p->next=NULL;


 */
    p=head;
    while (p!=NULL) {
        printf ("%d ",p->data);
        p=p->next;
    }

    reversed=reverseList(head);

    p=reversed;
    while (p!=NULL) {
        printf ("%d ",p->data);
        p=p->next;
    }

    return 0;
}
