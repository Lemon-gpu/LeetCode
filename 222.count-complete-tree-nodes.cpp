/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
private:
    int _depth = 0;
    int voidNode = 0;
    void depth(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        _depth++;
        depth(node->left);
    }

    bool iter(TreeNode *node, int currDepth)
    {
        if (currDepth == this->_depth)
        {
            if (node == nullptr)
            {
                this->voidNode++;
                return true;
            }
            else
            {
                return false;
            }
        }
        bool flag = iter(node->right, currDepth + 1);
        if (!flag)
        {
            return false;
        }
        flag = iter(node->left, currDepth + 1);
        if (!flag)
        {
            return false;
        }
        return true;
    }

public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        depth(root);
        iter(root, 1);
        return pow(2, _depth) - 1 - voidNode;
    }
};
// @lc code=end
