//
// Created by Will on 2/16/16.
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
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return work(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* work(vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri) {
        if (lp > rp)
            return NULL;
        TreeNode *root = new TreeNode (preorder[lp]);
        for (int k = li; k <= ri; k++) {
            if (preorder[lp] == inorder[k]) {
                root->left = work(preorder, inorder,lp + 1, lp + (k - li), li, k -1);
                root->right = work(preorder, inorder, lp + (k - li) + 1, rp, k + 1, ri);
            }
        }
        return root;
    }
};

int main() {
    vector<int> preorder{1,2,3,4,5,6};
    vector<int> inorder{2,3,1,5,4,6};
    TreeNode *root;
    Solution test;
    root = test.buildTree(preorder, inorder);
    cout<<root->val<<endl;
    cout<<root->left->val<<endl;
    cout<<root->right->val<<endl;
    return 0;
}