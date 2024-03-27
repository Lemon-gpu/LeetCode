#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

public:
    BinaryTreePrinter(TreeNode* root) : root(root) {}

    void print() {
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
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    BinaryTreePrinter printer(root);
    printer.print();

    return 0;
}
