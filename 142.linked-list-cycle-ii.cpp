/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
#include "General.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{

public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode* result = nullptr;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                fast = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                result = slow;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    // Test cases
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2; // Create a cycle

    Solution solution;
    ListNode *result = solution.detectCycle(head);

    if (result != nullptr)
    {
        cout << "Cycle detected at node with value: " << result->val << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    // Clean up
    delete head;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
