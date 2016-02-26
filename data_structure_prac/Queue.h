//
// Created by Will on 12/8/15.
//

// 设 队头指针指向队头元素,队尾指针指向对为元素的下一个位置;


#ifndef DATA_STRUCTURE_PRAC_QUEUE_H
#define DATA_STRUCTURE_PRAC_QUEUE_H

#include <iostream>
#define MaxSize 50
using namespace std;

                     //顺序队列


//---------------------------------------------------------------------------------------------------------------------- 链式队列
    typedef struct LinkNode {       //链式队列定义
        int data;
        struct LinkNode *next;
    }LinkNode;

    typedef struct {
        LinkNode *front, *rear;
    }LinkQueue;

    void InitQueue (LinkQueue &q) {      //初始化队列
        q.front=q.rear=(LinkNode*) malloc (sizeof(LinkNode));
        q.front->next=NULL;
    }

    bool IsEmpty (LinkQueue q) {          //判队空
        if (q.front==q.rear)
            return true;
        else
            return false;
    }

    void EnQueue (LinkQueue &q,int x) {   //入队
        LinkNode *s;
        s=(LinkNode *) malloc (sizeof(LinkNode));
        s->data=x; s->next=NULL;
        q.rear->next=s;
        q.rear=s;
    }

    bool DeQueue (LinkQueue &q, int &x) {   //出队
        LinkNode *p;

        if (q.front==q.rear)
            return false;

        p=q.front->next;           //q.front指向的结点的下一个节点才是队列的第一个节点
        x=p->data;
        q.front->next=p->next;
        if (q.rear==p)
            q.rear=q.front;                //若原队列中只有一个结点,删除后变空
        free (p);
    }

//----------------------------------------------------------------------------------------------------------------------

//********************************************************************************************************************** 顺序存储的队列

    typedef struct {
        int data[MaxSize];
        int front,rear;
    }SqQueue;


    void InitQueue (SqQueue &q) {         //初始化队列
        q.rear=q.front=0;

    }


    bool isEmpty (SqQueue q) {               //判空
        if (q.front==q.rear)
            return true;
        else
            return false;
    }

    bool EnQueue (SqQueue &q,int x) {                   // 入队
        if ((q.rear+1) % MaxSize==q.front)
            return false;                               //队满(循环队列)
        q.data[q.rear]=x;
        q.rear=(q.rear+1) % MaxSize;
        return true;
    }

    bool DeQueue (SqQueue &q, int &x) {              //出队
        if (q.rear==q.front)
            return false;            //队空
        x=q.data[q.front];
        q.front=(q.front+1) % MaxSize;    //队头指针加1取模
    }



//**********************************************************************************************************************
#endif //DATA_STRUCTURE_PRAC_QUEUE_H
