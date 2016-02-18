//
// Created by Will on 1/2/16.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include"linkList.h"
#include "treeNode.h"
using namespace std;


class Solution {
public:

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        TreeNode *t;
        if (!head->next) {
            t = (TreeNode *) malloc (sizeof(TreeNode));
            t->val = head->val;
            t->left = NULL; t->right = NULL;
            return t;
        }

        ListNode *pre, *fast, *slow, *mid;
        pre = (ListNode *) malloc (sizeof(ListNode));
        pre->next = head;
        slow = pre;
        fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow->next;
        slow->next = NULL;

        t = (TreeNode *) malloc (sizeof(TreeNode));
        t->val = mid->val;
        t->left = sortedListToBST(head);
        t->right = sortedListToBST(mid->next);
        return t;

    }
};
int main() {
    Solution test;
    ListNode *head;
    head = createLinklist();
    printList(head);


    TreeNode *t;
    t = test.sortedListToBST(head);

    TreeNode q[10];
    int head_q, tail_q;
    head_q = 0;
    tail_q = 1;
    q[0] = *t;

    while(head_q != tail_q) {
        TreeNode *temp;
        temp = &q[head_q];
        cout<<"   "<<temp->val;
        head_q++;

        if (temp->left) {
            q[tail_q] = *temp->left;
            tail_q++;
        }
        if (temp->right) {
            q[tail_q] = *temp->right;
            tail_q++;
        }

    }



    return 0;
}







