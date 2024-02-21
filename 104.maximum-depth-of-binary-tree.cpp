/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> q;
        int result = 0;
        q.push(root);
        q.push(new TreeNode(INT_MAX));

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->val == INT_MAX)
            {
                result++;
                delete curr;
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push(new TreeNode(INT_MAX));
                }
            }
            else
            {
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                }
            }
        }

        return result;
    }
};
// @lc code=end

