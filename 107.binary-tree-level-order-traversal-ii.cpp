/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> layer;
        vector<vector<int>> result;

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
                    result.push_back(layer);
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
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = solution.levelOrderBottom(root);

    for (const auto &layer : result)
    {
        for (const auto &val : layer)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
