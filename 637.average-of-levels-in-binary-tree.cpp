/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
class Solution
{
private:
    double average(vector<int> v)
    {
        long long result = 0;
        for (int i: v)
        {
            result += static_cast<long long>(i);
        }
        return static_cast<double>(result) / v.size();
    }
    TreeNode* splicer()
    {
        TreeNode* t = new TreeNode();
        t->left = t;
        t->right = t;
        return t;
    }

    bool detecter(TreeNode* t)
    {
        return t->left == t && t->right == t;
    }
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> layer;
        vector<double> result;

        if (root != nullptr)
        {
            q.push(root);
        }
        q.push(splicer());

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (detecter(curr))
            {
                if (!layer.empty())
                {
                    result.push_back(average(layer));
                }
                layer.clear();
                delete curr;
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push(splicer());
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

