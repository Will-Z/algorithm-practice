//
// Created by Will on 12/18/15.
//

#include <iostream>
#include "linkList.h"
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head){
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {           //存在环
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main() {
    Solution test;
    ListNode *head, *point;
    head = creatCircleList (5,2);

    point = test.detectCycle(head);
    if (point)
        cout<<point->val;
    else
        cout<<"NULL"<<endl;
    return 0;
}