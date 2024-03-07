/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */
#include "General.h"

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
private:
    int MaxDepth = 0;
    void _maxDepth(Node *root, int depth)
    {
        if (root->children.size() == 0)
        {
            this->MaxDepth = max(depth, this->MaxDepth);
        }

        for (Node *node : root->children)
        {
            _maxDepth(node, depth + 1);
        }
    }

public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        _maxDepth(root, 1);
        return this->MaxDepth;
    }
};
// @lc code=end
