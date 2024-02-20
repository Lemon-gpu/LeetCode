/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

#include "General.h"
// @lc code=start
class Solution
{
private:
    deque<int> d;
    void pop(int value)
    {
        if (!d.empty() && this->front() == value)
        {
            d.pop_front();
        }
    }

    void push(int value)
    {
        while (!d.empty() && value > d.back())
        {
            d.pop_back();
        }
        d.push_back(value);
    }

    int front()
    {
        return d.front();
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            this->push(nums[i]);
        }
        result.push_back(this->front());
        for (int i = k; i < nums.size(); i++)
        {
            this->pop(nums[i - k]);
            this->push(nums[i]);
            result.push_back(this->front());
        }
        return result;
    }
};
// @lc code=end
