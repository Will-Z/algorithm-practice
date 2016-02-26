//
// Created by Will on 12/3/15.
//

#ifndef LEETCODE_206_REVERSE_LINKED_LIST_H
#define LEETCODE_206_REVERSE_LINKED_LIST_H
#include <iostream>
using namespace std;

struct ListNode {
    int data;
    int val;                  // 此处仅为 迎合leetcode定义
    struct ListNode *next;
};

//----------------------------------------------------------------------------------------------------------------------
void printList (struct ListNode *head){   //打印以head为头结点的链表 如果链表为空 则打印"[]"
    struct ListNode *p=head;
    if (head==NULL)
        cout<<"[]"<<endl;
    while (p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

//----------------------------------------------------------------------------------------------------------------------

struct ListNode* creatSimpleList(int n){         //建立有n个节点的单链表 第i个节点的data为i
    struct ListNode *head,*p,*q;
    int num=0;
    if (n==0)
        return NULL;

    head=p=(struct ListNode*) malloc (sizeof(struct ListNode));
    head->data=1;
    head->val=1;
    num++;
    while (num<n) {
        num++;
        q=(struct ListNode*) malloc (sizeof(struct ListNode));
        q->data=num;
        q->val=num;
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return head;

}

struct ListNode* creatCircleList(int n,int k){         //建立有n个节点的单链表 第i个节点的data为i; 并且第n个节点末尾指针指向第k个节点 若k==0 则最后一个节点指向NULL;
    struct ListNode *head,*p,*q,*startCircle;
    int num=0;
    if (n==0 || k > n)
        return NULL;

    head=p=(struct ListNode*) malloc (sizeof(struct ListNode));
    head->data=1;
    head->val=1;
    num++;
    if (k == 1)
        startCircle = head;
    while (num<n) {
        num++;
        q=(struct ListNode*) malloc (sizeof(struct ListNode));
        q->data=num;
        q->val=num;
        if (num == k)
            startCircle = q;
        p->next=q;
        p=q;
    }
    if (k == 0)
        p->next=NULL;
    else
        p->next = startCircle;
    return head;

}



//----------------------------------------------------------------------------------------------------------------------

struct ListNode* createLinklist() {                      //由输入的整数建立单链表
    struct ListNode *head,*p1,*p2;
    int num,info;

    cin>>num;                                            //节点数   这里 num由参数传入会更好  可惜 前面好几个程序用到了此头文件   已不便于修改    败笔
    head=p1=p2=(struct ListNode*) malloc (sizeof(struct ListNode));
    if (num>0) {
        head=p1=p2=(struct ListNode*) malloc (sizeof(struct ListNode));
        cin >> info;
        head->data=info;
        head->val=info;
        num--;
    }
    else
        return NULL;

    while(num>0) {
        p2=(struct ListNode*) malloc (sizeof(struct ListNode));
        cin>>info;
        p2->data=info;
        p2->val=info;
        p1->next=p2;
        p1=p2;
        num--;
    }
    p2->next=NULL;
    return head;
}

#endif //LEETCODE_206_REVERSE_LINKED_LIST_H
