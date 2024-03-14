/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
enum DIRECTION {LEFT, RIGHT, ROOT};

class Solution {
private:
    int sum = 0;
    bool isLeaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    void goThrough(TreeNode* node, DIRECTION direction)
    {
        if (node == nullptr)
        {
            return; 
        }

        if (isLeaf(node) && direction == LEFT)
        {
            sum += node->val;
            return;
        }
        goThrough(node->left, LEFT);
        goThrough(node->right, RIGHT);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        goThrough(root, ROOT);
        return sum;
    }
};
// @lc code=end

