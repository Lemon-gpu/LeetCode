/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
#include "General.h"
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    private:
    Node *splitter()
    {
        Node *t = new Node();
        t->left = t;
        t->right = t;
        return t;
    }

    bool detecter(Node *t)
    {
        return t->left == t && t->right == t;
    }
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        Node *pre = nullptr;

        if (root != nullptr)
        {
            q.push(root);
        }
        q.push(splitter());

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (detecter(curr))
            {
                delete curr;
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push(splitter());
                }
                pre = nullptr;
            }
            else
            {
                if (pre != nullptr)
                {
                    pre->next = curr;
                }
                pre = curr;
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};
// @lc code=end

