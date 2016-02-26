//
// Created by Will on 12/9/15.
//

#ifndef DATA_STRUCTURE_PRAC_TREE_H
#define DATA_STRUCTURE_PRAC_TREE_H

#include <iostream>
#include "Stack.h"
using namespace std;


//----------------------------------------------------------------
typedef struct BiTNode {       //二叉树链式存储结构
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct ThreadNode {     //线索二叉树
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode, *ThreadTree;

//----------------------------------------------------------------  中序遍历的二叉树的线索化算法

void InThread (ThreadTree &p,ThreadTree &pre) {    //中序遍历对二叉树线索化的递归算法   [注] 此函数结束后 最后一个节点的 lchild ltag 是没有处理的,即最后一个节点未处理右线索
    if (p!=NULL) {
        InThread (p->lchild,pre);       //递归 线索化左子树
        if (p->lchild==NULL) {         //左子树为空 建立前驱线索
            p->lchild=pre;
            p->ltag=1;
        }
        if (pre!=NULL && pre->lchild==NULL) {    //建立前驱结点的后继线索
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread (p->rchild, pre);             //线索化右子树
    }
}
void CreateInThread (ThreadTree t){        //通过中序遍历建立中序线索二叉树的主过程
    ThreadTree pre=NULL;
    if (t!=NULL) {
        InThread (t,pre);
        pre->lchild=NULL;
        pre->ltag=1;
    }
}

//----------------------------------------------------------------  关于中序线索二叉树的一些操作

ThreadNode *FirstNode (ThreadNode *p) {    //返回中序线索二叉树中 中序序列下的  第一个节点
    while (p->ltag==0)                //本质就是求最左节点
        p=p->lchild;
    return p;

}

ThreadNode *NextNode (ThreadNode *p) {   //返回中序线索二叉树中 节点p 在中序序列下的后继节点
    if (p->rtag==0)
        return FirstNode (p->rchild);  //如果右子树不为空 返回右子树中 按中序遍历的第一个节点
    else
        return p->rchild;              // rtag==1 直接返回后继线索

}

void InOrder (ThreadNode *t) {
    for (ThreadNode *p=FirstNode(t); p!=NULL; p=NextNode(p))
        cout<<p->data<<" ";
}


//----------------------------------------------------------------

void visit (BiTree t) {
    cout<t->data;
}

void PreOrder(BiTree t) {       //先序遍历
    if (t!= NULL) {
        visit (t);
        PreOrder (t->lchild);
        PreOrder (t->rchild);
    }
}

void InOrder (BiTree t) {      //中序遍历
    if (t!=NULL) {
        PreOrder (t->lchild);
        visit (t);
        PreOrder (t->rchild);
    }
}

void PoOrder (BiTree t) {    //后序遍历
    if (t!=NULL) {
        PreOrder (t->lchild);
        PreOrder (t->rchild);
        visit (t);
    }
}









#endif //DATA_STRUCTURE_PRAC_TREE_H
