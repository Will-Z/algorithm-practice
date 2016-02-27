//
// Created by Will on 2/22/16.
//
#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* lt, TreeNode* rt) {
        if (!lt && !rt)
            return true;
        if (lt && !rt || !lt && rt || lt->val != rt->val)
            return false;
        return isSymmetric(lt->left, rt->right) && isSymmetric(lt->right, rt->left);

    }
};

int main() {
    TreeNode *root;
    root = (TreeNode *) malloc (sizeof(TreeNode));
    root->val = 1;
    root->left = (TreeNode *) malloc (sizeof(TreeNode));
    root->left->val = 2;

    root->left->left = NULL;
    root->left->right = NULL;
    root->right = NULL;


    Solution test;

    cout<<test.isSymmetric(root)<<endl;
    return 0;
}