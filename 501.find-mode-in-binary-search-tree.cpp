/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
private:
    int currentCount = 0;
    int maxCount = 0;
    TreeNode* prev = nullptr;
    vector<int> modes;

    void inorder(TreeNode* node) {
        if (!node) return;

        // 中序遍历左子树
        inorder(node->left);

        // 更新当前节点值的计数
        if (prev && prev->val == node->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        // 更新众数列表
        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes.clear();
            modes.push_back(node->val);
        } else if (currentCount == maxCount) {
            modes.push_back(node->val);
        }

        prev = node;

        // 中序遍历右子树
        inorder(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};

// @lc code=end

int main(int argc, char *argv[])
{
    Solution solution;

    // 创建一个二叉搜索树
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(20);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(10);
    root->right->left->left = new TreeNode(20);
    root->right->left->right = new TreeNode(20);

    // 调用 findMode 函数
    vector<int> result = solution.findMode(root);

    // 打印结果
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}