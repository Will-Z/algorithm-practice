//
// Created by Will on 1/18/16.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode *headOdd, *headEven, *odd, *even;

        headOdd = odd = head;
        headEven = even = head->next;
        while (odd->next && even->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        if (even)
            even->next = NULL;
        odd->next = headEven;
        return headOdd;
    }
};


int main() {
    Solution test;
    ListNode *head;
    head = createLinklist();
    printList(head);
    cout<<endl;
    head = test.oddEvenList(head);
    printList(head);
    return 0;
}