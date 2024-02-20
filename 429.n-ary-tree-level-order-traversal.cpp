/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */
#include "General.h"

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

class Solution {
private:
    Node* splitter()
    {
        Node* n = new Node();
        vector<Node*> c = {n};
        n->children = c;
        return n;
    }

    bool validation(Node* n) // True if n is splitter
    {
        return n->children.size() != 0 && n->children[0] == n;
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> layer;
        vector<vector<int>> result;
        queue<Node*> q;

        q.push(root);
        q.push(splitter());

        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            if (validation(curr))
            {
                result.push_back(layer);
                layer.clear();
                delete curr;
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push(this->splitter());
                }
            }
            else
            {
                for (Node* n: curr->children)
                {
                    q.push(n);
                }
                layer.push_back(curr->val);
            }
        }
        return result;
    }
};
// @lc code=end

