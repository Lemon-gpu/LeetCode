/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
#include"General.h"
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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) { return nullptr; }
        if (nums.size() == 1) { return new TreeNode(nums[0]); }

        TreeNode* centerNode = new TreeNode(nums[nums.size() / 2]);
        vector<int> leftArray = vector<int>(nums.begin(), nums.begin() + nums.size() / 2);
        vector<int> rightArray = vector<int>(nums.begin() + nums.size() / 2 + 1, nums.end());
        centerNode->left = sortedArrayToBST(leftArray);
        centerNode->right = sortedArrayToBST(rightArray);
        return centerNode;

    }
};
// @lc code=end

