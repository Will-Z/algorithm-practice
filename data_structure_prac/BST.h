 //
// Created by Will on 12/9/15.
//

#ifndef DATA_STRUCTURE_PRAC_BST_H
#define DATA_STRUCTURE_PRAC_BST_H

#include <iostream>
 using namespace std;

 typedef struct BiTNode {       //二叉树链式存储结构
     int data;
     struct BiTNode *lchild, *rchild;
 } BiTNode, *BiTree;



 //---------------------------------------------------------------------------------------------------------------------

 BiTNode *BST_Search (BiTree t, int key, BiTNode *&p) {       //返回指向关键字为key的节点指针 若不存在 则返回NULL
     p=NULL;                                                   //p指向被查找节点的父节点,  是为了便于插入和删除操作使用
     while (t!=NULL && key!=t->data) {
         p=t;
         if (key<t->data)
            t=t->lchild;
         else
             t=t->rchild;
     }
     return t;
 }

 //---------------------------------------------------------------------------------------------------------------------

 int BST_Insert (BiTree &t, int x) {    //在二叉树t中插入一个关键字为x的节点
     if (t==NULL) {
         t=(BiTree) malloc (sizeof(BiTree));
         t->data=x;
         t->lchild=t->rchild=NULL;
         return 1;                      //插入成功返回1
     }
     else if(x==t->data)
         return 0;                      //树中存在相同节点 插入失败 返回0
     else if(x<t->data)
         return BST_Insert(t->lchild,x);
     else
         return BST_Insert(t->rchild,x);
 }

 //---------------------------------------------------------------------------------------------------------------------

 void Create_BST (BiTree &t, int str[], int n){         //用关键字数组str[]建立一个二叉排序树
     t=NULL;
     int i=0;
     while (i<n) {
         BST_Insert (t,str[i]);
         i++;
     }
 }








#endif //DATA_STRUCTURE_PRAC_BST_H