/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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

class BinaryTreePrinter {
private:
    TreeNode* root;
    map<int, vector<pair<int, TreeNode*>>> nodes; // key: column, value: list of pairs (row, node)
    int minColumn = 0;
    int maxColumn = 0;

    void findPositions(TreeNode* node, int row, int column) {
        if (!node) return;
        nodes[column].emplace_back(row, node);
        minColumn = min(minColumn, column);
        maxColumn = max(maxColumn, column);
        findPositions(node->left, row + 1, column - 1);
        findPositions(node->right, row + 1, column + 1);
    }

    int treeHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(treeHeight(node->left), treeHeight(node->right));
    }

    void clear() {
        nodes.clear();
        minColumn = 0;
        maxColumn = 0;
    }

public:
    void print(TreeNode* root) {
        if (!root) return;

        findPositions(root, 0, 0);
        int height = treeHeight(root);

        vector<string> canvas(height * 2 - 1, string(maxColumn - minColumn + 1, ' '));

        for (auto& col : nodes) {
            auto& vec = col.second;
            sort(vec.begin(), vec.end(), [](const pair<int, TreeNode*>& a, const pair<int, TreeNode*>& b) {
                return a.first < b.first;
            });
            for (auto& row_node : vec) {
                int row = row_node.first * 2;
                TreeNode* node = row_node.second;
                canvas[row][col.first - minColumn] = '0' + node->val;
                if (node->left) {
                    canvas[row + 1][col.first - minColumn - 1] = '/';
                }
                if (node->right) {
                    canvas[row + 1][col.first - minColumn + 1] = '\\';
                }
            }
        }

        for (auto& line : canvas) {
            for (char ch : line) {
                cout << (ch == ' ' ? ' ' : ch);
            }
            cout << endl;
        }

        clear();
    }
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
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) { return root; }
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);
        return root;
    }
};
// @lc code=end

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    TreeNode* root = nullptr;
    BinaryTreePrinter b;

    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 6);
    root = insertIntoBST(root, 8);
    b.print(root);

    root = Solution().convertBST(root);

    b.print(root);
    return 0;

}



