/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */
#include "General.h"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

class Solution
{
private:
    int judgeState(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int result = 0;
        if (root->val == p->val || root->val == q->val) { return result; }
        if (root->val > p->val)
        {
            if (root->val < q->val)
            {
                result = 0;
            }
            else
            {
                result = -1;
            }
        }
        else
        {
            if (root->val > q->val)
            {
                result = 0;
            }
            else
            {
                result = 1;
            }
        }
        return result;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return root;
        }
        switch (judgeState(root, p, q))
        {
        case -1:
            return lowestCommonAncestor(root->left, p, q);
            break;
        case 0:
            return root;
            break;
        case 1:
            return lowestCommonAncestor(root->right, p, q);
            break;
        }
        return nullptr;
    }
};
// @lc code=end
