//
// Created by Will on 12/10/15.
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
    bool isPalindrome(ListNode* head) {
        ListNode *fast,*slow,*p1,*p2;
        fast=slow=head;
        while (fast && fast->next) {    //若奇数个节点 则slow指向中间节点 fast指向最后节点
            fast=fast->next->next;      //弱偶数个节点 则slow 指向中间两个节点中右边的一个   fast指向最后一个节点后的NULL
            slow=slow->next;
        }
        p1=NULL;
        while (slow) {     //将链表后半部分反转
            p2=slow->next;
            slow->next=p1;
            p1=slow;
            slow=p2;
        }
        while(head && p1) {
            if (head->val != p1->val)
                return false;
            head=head->next;
            p1=p1->next;
        }
        return true;

    }
};


int main() {
    Solution test;
    ListNode *head;
    head=createLinklist();
    if (test.isPalindrome(head))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}