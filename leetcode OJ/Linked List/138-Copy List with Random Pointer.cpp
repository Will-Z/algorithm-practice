//
// Created by Will on 1/19/16.
//

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;

        RandomListNode *p, *p1, *p2, *nhead;
        p = head;
        while (p) {
            p1 = p;
            p2 = (RandomListNode *) malloc (sizeof(RandomListNode));
            p2->label = p1->label;
            p2->next = p1->next;
            p2->random = p1->random;
            p1->next = p2;
            p = p->next->next;
        }

        nhead = p2 = head->next;


        while (p2->next) {
            if (p2->random)
                p2->random = p2->random->next;
            else
                p2->random = NULL;
            p2 = p2->next->next;
        }
        if (p2->random)
            p2->random = p2->random->next;
        else
            p2->random = NULL;



        p1 = head;
        p2 = head->next;
        while (p2->next) {
            p1->next = p1->next->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }


        p1->next = NULL;
        return nhead;
    }
};

int main() {
    RandomListNode *p1, *p2, *p3, *head;
    p1 = (RandomListNode *) malloc (sizeof(RandomListNode));
    p2 = (RandomListNode *) malloc (sizeof(RandomListNode));
    p3 = (RandomListNode *) malloc (sizeof(RandomListNode));
    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;
    p1->label = 1;
    p2->label = 2;
    p3->label = 3;
    p1->random = p3;
    p2->random = p1;
    p3->random = p1;

    Solution test;

    head = test.copyRandomList(p1);

    cout<<head->label<<"    "<<head->next->label<<"          "<<head->next->next->label<<endl;
    cout<<head->next->label<<"      "<<head->next->next->label<<"      "<<head->next->next->next<<endl;
    cout<<head->random->label<<"    "<<head->next->random->label<<"     "<<head->next->next->random->label<<endl;
    return 0;
}