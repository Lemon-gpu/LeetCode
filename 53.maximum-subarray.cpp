/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include "General.h"

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = INT_MIN;
        int currSum = 0;

        for (int i: nums)
        {
            currSum += i;
            currMax = max(currSum, currMax);
            currSum = max(0, currSum);
        }
        return currMax;
    }
};
// @lc code=end

