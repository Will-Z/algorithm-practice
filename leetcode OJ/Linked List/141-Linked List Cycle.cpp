//
// Created by Will on 12/13/15.
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
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast,*slow;
        if (!head)
            return false;
        fast = slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
int main () {
    ListNode *head;
    Solution test;

    //head = (ListNode *) malloc (sizeof (ListNode));
    //head->next = NULL;
    head = NULL;

    if (test.hasCycle(head))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}