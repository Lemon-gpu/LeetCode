/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    TreeNode *splitter()
    {
        TreeNode *t = new TreeNode();
        t->left = t;
        t->right = t;
        return t;
    }

    bool detecter(TreeNode *t)
    {
        return t->left == t && t->right == t;
    }

public:
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> q;
        long long curr_max = LLONG_MAX;
        vector<int> result;

        if (root != nullptr)
        {
            q.push(root);
        }
        q.push(splitter());

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (detecter(curr))
            {
                if (curr_max != LLONG_MAX)
                {
                    result.push_back(static_cast<int>(curr_max));
                    curr_max = LLONG_MAX;
                }
                delete curr;
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push(splitter());
                }
            }
            else
            {
                if (curr_max == LLONG_MAX)
                {
                    curr_max = curr->val;
                }
                else
                {
                    curr_max = max(curr_max, static_cast<long long>(curr->val));
                }
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
