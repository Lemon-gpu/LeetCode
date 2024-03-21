/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    vector<int> seq;
    void mid(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        mid(root->left);
        seq.push_back(root->val);
        mid(root->right);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        mid(root);
        for (int i = 1; i < seq.size(); i++)
        {
            if (seq[i - 1] >= seq[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

