//
// Created by Will on 3/2/16.
//

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
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && !q || !p && q)
            return false;
        if (p && q && p->val != q->val)
            return false;
        if (!p && !q)
            return true;
        return isSameTree(q->right, p->right) && isSameTree(p->left, q->left);

    }
};