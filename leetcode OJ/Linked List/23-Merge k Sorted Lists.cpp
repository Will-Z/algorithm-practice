//
// Created by Will on 1/19/16.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include "linkList.h"
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeLists(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *p1, *p2, *p, *pp, *head, *pre;
        p1 = l1;
        p2 = l2;

        pre = (ListNode *) malloc (sizeof(ListNode));
        p = pre;

        while (p1 && p2) {
                if (p1->val <= p2->val) {
                    p->next = p1;
                    p1 = p1->next;
                    p = p->next;
                } else {
                    p->next = p2;
                    p2 = p2->next;
                    p = p->next;
                }
        }
        if (!p1)
            p->next = p2;
        else if (!p2)
            p->next = p1;
        return pre->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        return mergeKLists(lists, 0, lists.size() - 1);
    }

     ListNode* mergeKLists(vector<ListNode*>& lists, int i, int j) {
        if (i == j) {
            return lists[i];
        }

        ListNode* a = lists[i];
        ListNode* b = lists[j];
        if (j - i >= 2) {
            int middle = i + (j - i) / 2;
            a = mergeKLists(lists, i, middle);
            if (middle + 1 != j) {
                b = mergeKLists(lists, middle + 1, j);
            }
        }
        return mergeLists(a,b);
    }
};

int main() {
    Solution test;
    ListNode *head1, *head2, *head;
    vector<ListNode*> lists(3);
    lists[0] = createLinklist();
    lists[1] = createLinklist();
    lists[2] = createLinklist();

    printList(lists[0]);
    printList(lists[1]);
    printList(lists[2]);

    head = test.mergeKLists(lists);
    printList(head);
    return 0;
}