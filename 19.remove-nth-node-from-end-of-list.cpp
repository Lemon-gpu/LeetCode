/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

#include "General.h"
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;

        ListNode* slow = newHead;
        ListNode* fast = newHead;

        while (n > 0)
        {
            fast = fast->next;
            n--;
        }

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        fast = slow->next;
        slow->next = slow->next->next;
        head = newHead->next;

        delete fast;
        delete newHead;

        return head;

    }
};
// @lc code=end

int main()
{
    // Create a linked list
    ListNode* head = new ListNode(1);

    // Create an instance of the Solution class
    Solution solution;

    // Call the removeNthFromEnd function
    int n = 1;
    ListNode* result = solution.removeNthFromEnd(head, n);

    // Print the resulting linked list
    ListNode* current = result;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the memory
    delete result;

    return 0;
}

