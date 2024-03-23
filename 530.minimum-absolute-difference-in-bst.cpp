/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int prev = -1;
    int _min = INT_MAX;
    void mid(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        mid(root->left);
        if (prev != -1)
        {
            _min = min(_min, abs(root->val - prev));
        }
        prev = root->val;
        mid(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        mid(root);
        return _min;
    }
};
// @lc code=end

