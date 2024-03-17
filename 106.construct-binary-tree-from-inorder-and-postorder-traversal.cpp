/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int searchIndex(vector<int>& list, int target)
    {
        int index = -1;
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i] == target)
            {
                index = i;
                break;
            }
        }
        return index;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty())
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode (*(postorder.end() - 1));
        postorder.pop_back();

        int rootIndex = searchIndex(inorder, root->val);
        vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder = vector<int>(inorder.begin() + rootIndex + 1, inorder.end());

        root->right = buildTree(rightInorder, postorder);
        root->left = buildTree(leftInorder, postorder);

        return root;

    }
};
// @lc code=end

