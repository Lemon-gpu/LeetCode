/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    TreeNode* splitter()
    {
        TreeNode* n = new TreeNode();
        n->left = n;
        n->right = n;
        return n;
    }

    bool isSplitter(TreeNode* n)
    {
        return n->left == n && n->right == n;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> s;
        TreeNode* leftMost = nullptr;

        s.push(root);
        s.push(splitter());

        while (!s.empty())
        {
            TreeNode* curr = s.front();
            s.pop();

            if (isSplitter(curr))
            {
                if (s.empty())
                {
                    break;
                }
                s.push(splitter());
                continue;
            }
            leftMost = curr;

            if (curr->right != nullptr)
            {
                s.push(curr->right);
            }
            if (curr->left != nullptr)
            {
                s.push(curr->left);
            }
        }

        return leftMost->val;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    /*
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8); // new leaf node
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9); // new leaf node
    */

    int result = solution.findBottomLeftValue(root);
    std::cout << "The bottom left value of the tree is: " << result << std::endl;

    return 0;
}

