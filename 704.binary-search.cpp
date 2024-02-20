/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

#include "General.h"

// @lc code=start

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 1) return nums[0] == target ? 0 : -1;

        int left = 0;
        int right = nums.size();
        while (left < right) 
        {
            int middle = left + (right - left >> 1);
            if (nums[middle] >= target)
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
};


// @lc code=end


int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> nums = {1};
    cout << s.search(nums, 1);
    return 0;
}

