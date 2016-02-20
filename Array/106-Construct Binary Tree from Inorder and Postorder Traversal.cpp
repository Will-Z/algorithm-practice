//
// Created by Will on 2/17/16.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return work(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* work(vector<int>& inorder, vector<int>& postorder,int li, int ri, int lp, int rp) {
        if (lp > rp)
            return NULL;
        TreeNode *root = new TreeNode(postorder[rp]);
        for (int k = li; k <= ri; k++)
            if (inorder[k] == postorder[rp]) {
                root->left = work(inorder, postorder,li, k - 1,lp, lp + (k - li) - 1);
                root->right = work(inorder, postorder,k + 1, ri, lp + (k - li), rp - 1);
            }
        return root;
    }
};

int main() {
    vector<int> inorder{2,3,1,5,4,6};
    vector<int> postorder{3,2,5,6,4,1};
    TreeNode *ans;
    Solution test;
    ans = test.buildTree(inorder, postorder);
    cout<<ans->val<<endl;
    cout<<ans->left->val<<endl;
    cout<<ans->right->val<<endl;
    cout<<ans->left->right->val<<endl;
    return 0;
}