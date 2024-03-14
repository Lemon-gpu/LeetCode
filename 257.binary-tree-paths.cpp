/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<int> orders;
    vector<string> result;

    bool isLeaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    void pushResult()
    {
        string s = "";
        for (int i = 0; i < orders.size(); i++)
        {
            s += to_string(orders[i]);
            if (i < orders.size() - 1)
            {
                s += "->";
            }
        }
        result.push_back(s);
    }

    void goThrough(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        orders.push_back(node->val);
        if (isLeaf(node))
        {
            pushResult();
        }
        goThrough(node->left);
        goThrough(node->right);
        orders.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        goThrough(root);
        return this->result;
    }
};
// @lc code=end

