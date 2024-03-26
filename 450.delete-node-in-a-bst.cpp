/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    bool isLeaf(TreeNode *node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    pair<TreeNode *, TreeNode *> findMaxNode(TreeNode *node)
    /**
     * 有三种返回可能
     * 1. prev和curr都是nullptr，那么意味着这个node本身就是个nullptr
     * 2. prev是nullptr，那么curr一定已经是最右边的节点
     * 3. 都不是nullptr，那么这个查找是normal的。
     */
    {
        TreeNode *prev = nullptr;
        TreeNode *curr = node;
        while (curr != nullptr && curr->right != nullptr)
        {
            prev = curr;
            curr = curr->right;
        }
        return {prev, curr};
    }

    pair<TreeNode *, TreeNode *> findMinNode(TreeNode *node)
    /**
     * 有三种返回可能
     * 1. prev和curr都是nullptr，那么意味着这个node本身就是个nullptr
     * 2. prev是nullptr，那么curr一定已经是最左边的节点
     * 3. 都不是nullptr，那么这个查找是normal的。
     */
    {
        TreeNode *prev = nullptr;
        TreeNode *curr = node;
        while (curr != nullptr && curr->left != nullptr)
        {
            prev = curr;
            curr = curr->left;
        }
        return {prev, curr};
    }

    tuple<TreeNode *, TreeNode *, bool> findNode(TreeNode *root, int key)
    /**
     * 有四种返回可能
     * 1. prev和curr都是nullptr，那么root就是nullptr
     * 2. 只有prev是nullptr，那么root是要找的节点
     * 3. 只有curr是nullptr，那就意味着找不到
     * 4. 都不是nullptr，那么是一个平常查找，方向通过第三个参数isLeft来判断
     */
    {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        bool isLeft = false;
        while (curr != nullptr)
        {
            if (curr->val > key)
            {
                prev = curr;
                curr = curr->left;
                isLeft = true;
            }
            else
            {
                if (curr->val < key)
                {
                    prev = curr;
                    curr = curr->right;
                    isLeft = false;
                }
                else
                {
                    break;
                }
            }
        }
        return {prev, curr, isLeft};
    }
    TreeNode *reConstruction(TreeNode *node)
    {
        auto [prev, curr] = findMaxNode(node->left);
        if (prev == nullptr && curr == nullptr) // fallback
        {
            auto [prev, curr] = findMinNode(node->right);
            if (prev == nullptr && curr == nullptr) { return nullptr; }

            node->val = curr->val;
            if (prev == nullptr)
            {
                node->right = curr->right;
            }
            else
            {
                prev->left = curr->right;
            }
        }
        else
        {
            node->val = curr->val;
            if (prev == nullptr)
            {
                node->left = curr->left;
            }
            else
            {
                prev->right = curr->left;
            }
        }
        return node;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        auto [prev, curr, isLeft] = findNode(root, key);
        if (curr == nullptr) { return root; }
        if (prev == nullptr)
        {
            root = reConstruction(root);
        }
        else
        {
            if (isLeaf(curr))
            {
                if (isLeft)
                {
                    prev->left = nullptr;
                }
                else
                {
                    prev->right = nullptr;
                }
            }
            else
            {
                curr = reConstruction(curr);
                if (isLeft)
                {
                    prev->left = curr;
                }
                else
                {
                    prev->right = curr;
                }
            }
        }
        return root;
    }
};
// @lc code=end

void printTree(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    printTree(node->left);
    std::cout << node->val << " ";
    printTree(node->right);
};

int main(int argc, char const *argv[])
{
    // Create a binary search tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // Create a Solution object
    Solution solution;

    // Delete a node
    root = solution.deleteNode(root, 3);

    // Print the tree
    printTree(root);
    std::cout << std::endl;

    return 0;
}
