/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */
#include "General.h"
struct TreeNode
{
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
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *curr = root;
        if (root == nullptr) { return new TreeNode(val); }
        while (curr != nullptr)
        {
            if (val > curr->val)
            {
                if (curr->right == nullptr)
                {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
            else
            {
                if (curr->left == nullptr)
                {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            }
        }
        return root;
    }
};
// @lc code=end
