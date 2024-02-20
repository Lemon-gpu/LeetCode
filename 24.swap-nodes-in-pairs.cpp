/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
private:
    ListNode *swapTwoNode(ListNode *pre, ListNode *curr)
    {
        if (curr == nullptr)
        {
            return pre;
        }
        else
        {
            ListNode* next = curr->next == nullptr ? nullptr : swapTwoNode(curr->next, curr->next->next);
            pre->next = next;
            curr->next = pre;
        }
        return curr;
    }

public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        return swapTwoNode(head, head->next);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;

    // Test case 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    ListNode* result1 = solution.swapPairs(head1);
    // TODO: Check the result

    // Test case 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    ListNode* result2 = solution.swapPairs(head2);
    // TODO: Check the result

    // Test case 3
    ListNode* head3 = new ListNode(1);
    ListNode* result3 = solution.swapPairs(head3);
    // TODO: Check the result

    return 0;
}

