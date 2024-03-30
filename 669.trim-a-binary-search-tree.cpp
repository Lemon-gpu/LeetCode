/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
    stack<TreeNode *> list;
    pair<TreeNode *, TreeNode *> findMaxNode(TreeNode *root)
    /**
     * 1. (prev == nullptr && curr == nullptr) --> root == nullptr
     * 2. (prev == nullptr && curr != nullptr) --> root->right == nullptr
     * 3. (prev != nullptr && curr != nullptr) --> default
     */
    {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr != nullptr && curr->right != nullptr)
        {
            prev = curr;
            curr = curr->right;
        }
        return {prev, curr};
    }

    pair<TreeNode *, TreeNode *> findMinNode(TreeNode *root)
    /**
     * 1. (prev == nullptr && curr == nullptr) --> root == nullptr
     * 2. (prev == nullptr && curr != nullptr) --> root->left == nullptr
     * 3. (prev != nullptr && curr != nullptr) --> default
     */
    {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr != nullptr && curr->left != nullptr)
        {
            prev = curr;
            curr = curr->left;
        }
        return {prev, curr};
    }

    tuple<TreeNode *, TreeNode *, bool> findNode(TreeNode *root, TreeNode *target)
    /**
     * 1. (prev == nullptr && curr == nullptr) --> root == nullptr
     * 2. (prev != nullptr && curr == nullptr) --> search failed
     * 3. (prev == nullptr && curr != nullptr) --> root == target
     * 4. (prev != nullptr && curr != nullptr) --> default
     */
    {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        bool isLeft = false;
        while (curr != nullptr)
        {
            if (curr == target)
            {
                return {prev, curr, isLeft};
            }
            prev = curr;
            if (curr->val > target->val)
            {
                curr = curr->left;
                isLeft = true;
            }
            else
            {
                curr = curr->right;
                isLeft = false;
            }
        }
        return {prev, curr, isLeft};
    }

    TreeNode *reconstruction(TreeNode *node)
    {
        TreeNode *left = node->left;
        TreeNode *right = node->right;

        if (left == nullptr) { return right; }
        if (right == nullptr) { return left; }

        auto [prev, curr] = findMaxNode(left);
        if (prev == nullptr && curr != nullptr)
        {
            node->val = curr->val;
            node->left = curr->left;
        }
        else if (prev != nullptr && curr != nullptr)
        {
            node->val = curr->val;
            prev->right = curr->left;
        }
        return node;
    }

    TreeNode *deleteNode(TreeNode *root, TreeNode *target)
    {
        auto [prev, curr, isLeft] = findNode(root, target);
        if (prev == nullptr && curr == nullptr)
        {
            root = nullptr;
        }
        else if (prev != nullptr && curr == nullptr)
        {
            root = nullptr;
        }
        else if (prev == nullptr && curr != nullptr)
        {
            root = reconstruction(curr);
        }
        else if (prev != nullptr && curr != nullptr)
        {
            curr = reconstruction(curr);
            if (isLeft)
            {
                prev->left = curr;
            }
            else
            {
                prev->right = curr;
            }
        }
        return root;
    }
    void midTravel(TreeNode *node, int low, int high)
    {
        if (node == nullptr)
        {
            return;
        }
        midTravel(node->left, low, high);
        if (!(node->val >= low && node->val <= high))
        {
            list.push(node);
        }
        midTravel(node->right, low, high);
    }


public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr) { return root; }
        if (root->val < low) { return trimBST(root->right, low, high); }
        if (root->val > high) { return trimBST(root->left, low, high); }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    // 创建测试用例
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    // 创建解决方案对象
    Solution solution;

    // 调用函数进行测试
    TreeNode *result = solution.trimBST(root, 1, 3);

    return 0;
}