/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    int getMaxIndex(vector<int>& nums)
    {
        int index = -1;
        int currMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (currMax < nums[i])
            {
                currMax = nums[i];
                index = i;
            }
        }
        return index;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
        {
            return nullptr;
        }

        int index = getMaxIndex(nums);
        TreeNode* root = new TreeNode(nums[index]);

        vector<int> leftNums = vector<int>(nums.begin(), nums.begin() + index);
        vector<int> rightNums = vector<int>(nums.begin() + index + 1, nums.end());

        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);

        return root;
    }
};
// @lc code=end

