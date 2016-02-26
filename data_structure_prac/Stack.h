//
// Created by Will on 12/8/15.
//
// 关于栈: 初始化栈顶为-1, 既top==-1为栈空

//

#ifndef DATA_STRUCTURE_PRAC_STACK_H
#define DATA_STRUCTURE_PRAC_STACK_H

#include <iostream>
#define MaxSize 50
using namespace std;


    typedef struct {                       //顺序栈
        int data[MaxSize];
        int top;
    } SqStack;

    typedef struct Linknode {
        int data;
        struct Linknode *next;
    } *LiStack;

    void InitStack (SqStack &s) {    //初始化栈  栈顶为-1
        s.top=-1;
    }


    bool StackEmpty(SqStack s) {    //判空
        if (s.top==-1)
            return true;
        else
            return false;
    }

    bool Push (SqStack &s,int x) {       //进栈  若栈满 返回 false
        if (s.top==MaxSize-1)
            return false;
        s.data[++s.top]=x;
        return true;
    }

    bool Pop(SqStack &s, int &x) {        //出栈
        if (s.top==-1)                    //若栈空 报错
            return false;
        x=s.data[s.top--];        //先出栈 然后栈顶元素-1
        return true;
    }

    bool GetTop (SqStack s, int &x) {     //读栈顶元素
        if (s.top==-1)
            return false;
        x=s.data[s.top];
        return true;
    }




#endif //DATA_STRUCTURE_PRAC_STACK_H
