/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return checkSymmetric(root->left, root->right);
    }

    bool checkSymmetric(TreeNode* leftNode, TreeNode* rightNode){
        if (leftNode == nullptr && rightNode == nullptr)
            return true;
        else if (leftNode == nullptr || rightNode == nullptr)
            return false;
        else if (leftNode->val == rightNode->val)
            return checkSymmetric(leftNode->left, rightNode->right) && checkSymmetric(leftNode->right, rightNode->left);
        else
            return false;
    }
};
// @lc code=end

