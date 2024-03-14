/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include "General.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int treeHeight(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = treeHeight(node->left);
        int right = treeHeight(node->right);

        int result = -1;

        if (!(left == -1 || right == -1) && abs(left - right) <= 1)
        {
            result = max(left, right) + 1;
        }
        return result;
    }
public:
    bool isBalanced(TreeNode* root) {
        return treeHeight(root) != -1;
    }
};
// @lc code=end

