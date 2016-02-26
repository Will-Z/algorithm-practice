//
// Created by Will on 11/13/15.
//

#ifndef DATA_STRUCTURE_PRAC_0_H
#define DATA_STRUCTURE_PRAC_0_H
#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

int CountX(LNode* HL, int x){     //1-1
    int count=0;
    LNode *p=HL;
    while(p!=NULL){
        if(p->data==x)
            count++;
    }
    return count;
}


void quickpass(int a[], int s, int t){  //2-1   本质就是一趟快排
    int i,j,x;
    i=s; j=t; x=a[s];
    while (i<j){
        while (i<j && a[j]>x)
            j--;
        if (i<j){
            a[i]=a[j]; i++;
        }
        while (i<j && a[i]<x)
            i++;
        if (i<j){
            a[j]=a[i]; j--;
        }
    }
    a[i]=x;

}

typedef struct node{              //2-2   计算C   C=A交B
    int data;
    struct node *next;
}lklist;

void intersection(lklist *ha, lklist *hb, lklist *hc){
    lklist *p,*q,*t;
    for (p=ha,hc=NULL;p!=NULL;p=p->next){
        for(q=hb;q!=NULL;q=q->next)
            if(q->data==p->data)
                break;
        if (q!=NULL){                                //头插法
            t=(lklist *)malloc(sizeof(lklist));
            t->data=p->data;
            t->next=hc;
            hc=t;
        }
    }
}

void delredundant (lklist *&head){   //3-1删除值相同的多余节点
    lklist *p,*q,*s;
    for (p=head;p!=NULL;p=p->next){
        for (q=p->next,s=q;q!=NULL;)
            if(p->data==q->data){
                s->next=q->next;
                free(q);
                q=q->next;
            }
            else{
                s=q;
                q=q->next;
            }

    }
}

typedef struct node1{              //3-2  求节点值等于x的节点在二叉树中的双亲
    int data;
    struct node1 *lchild, *rchild;
}bitree;

bitree *q[20];
int r=0,f=0,flag=0;
void preorder (bitree *bt, char x){
    if (bt!=NULL && flag==0)
        if (bt->data==x){
            flag=1;
            return;
        }
        else{
            r=(r+1)%20;
            q[r]=bt;
            preorder (bt->lchild,x);
            preorder (bt->rchild,x);
        }
}

void parent (bitree *bt, char x){
    int i;
    preorder(bt,x);
    for (i=0;i<=r;i++)
        if (q[i]->lchild->data==x || q[i]->rchild->data==x)
            break;
    if (flag==0)
        cout<<"not found x"<<endl;
    else if(i<=r)
        cout<<q[i]->data<<endl;
    else
        cout<<"no parents"<<endl;
}


void split (lklist *head, lklist *&ha, lklist *&hb, lklist *&hc){    //4-1   这个你看的明白
    lklist *p;
    ha=NULL; hb=NULL; hc=NULL;
    for (p=head;p!=NULL;p=p->next){
        if (p->data>='A' && p->data<='B'){
            p->next=ha;ha=p;
        }
        else if (p->data>='0' && p->data<='9'){
            p->next=hb;hb=p;
        }
        else{
            p->next=hc;hc=p;
        }
    }
}

void swapbitree (bitree *bt){           //4-2交换左右子树
    bitree *p;
    if (bt==0)
        return;
    swapbitree (bt->lchild);
    swapbitree (bt->rchild);
    p=bt->lchild; bt->lchild=bt->rchild; bt->rchild=p;
}


void bstinsert (bitree *&bt, int x){   //4-3 建一个二叉排序树
    if (bt==0){
        bt=(bitree *)malloc(sizeof(bitree));
        bt->data=x;
        bt->lchild=NULL;
        bt->rchild=NULL;
    }
    else if (bt->data>x)
        bstinsert (bt->lchild,x);
    else
        bstinsert (bt->rchild,x);
}


void createbst (bitree *&bt){
    int x;
    for (int i=1;i<=100;i++){
        cin>>x;
        bstinsert (bt,x);
    }
}

int judgebitree(bitree *bt1, bitree *bt2){    //5-1 判断两个二叉树是否相同
    if (bt1==NULL && bt2==NULL)
        return 1;
    if (bt1!=NULL|| bt2!=NULL || bt1->data!=bt2->data)
        return 0;
    else return (judgebitree(b1->lchild,bt2->lchild)&judgebitree(bt1->rchild,br2->rchild));
}

void mergelklist (lklist *ha, lklist *hb){    //5-2;两个单链表归并
    lklist *hc,*q;
    hc=q=NULL;
    while (ha!=NULL && hb!=NULL){
        if (ha->data<hb->data){
            if (hc==NULL)
                hc=q=ha;
            else{
                q->next=ha;
                ha=ha->next;
            }
        }
        else{
            if (hc==NULL)
                hc=q=hb;
            else{
                q->next=hb;
                hb=hb->next;
            }
        }
    }

    if (ha==NULL)
        q->next=hb;
    else
        q->next=ha;
}

struct record{
    int key,others;
};

int bisearch (struct record a[],int x){    //6-1   裸二分
    int mid,high,low;
    low=0; high=n-1;
    while (low<=high){
        mid=(low+high)/2;
        if (a[mid].key==x)
            return mid;
        else if(a[mid].key>x)
            high=mid-1;
        else
            low=mid+1;

    }
}
int minnum=(numeric_limits<int>::min)();    //6-2 判断是不是二叉排序树; p.s. 如果你不喜欢这么写 你可以判断中序遍历序列是否递增  其实本质一样;
int flag=1;
void inorder(bitree *bt){
    if (bt!=NULL){
        inorder(bt->lchild);
        if(minnum>bt->data)
            flag=0;
        minnum=bt->data;
        inorder(bt->rchild);
    }
}


#endif //DATA_STRUCTURE_PRAC_0_H
