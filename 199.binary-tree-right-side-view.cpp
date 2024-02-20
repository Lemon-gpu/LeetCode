/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> layer;
        vector<int> result;

        if (root != nullptr)
        {
            q.push(root);
        }
        q.push(new TreeNode(INT_MAX));

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->val == INT_MAX)
            {
                if (!layer.empty())
                {
                    result.push_back(layer[layer.size() - 1]);
                }
                layer.clear();
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
                layer.push_back(curr->val);
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

