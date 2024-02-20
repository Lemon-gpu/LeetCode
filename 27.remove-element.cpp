/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include "General.h"
// @lc code=start
class Solution {
    int count = 0;

public:
    int removeElement(vector<int>& nums, int val) 
    {
        int left = 0;
        int right = nums.size() - 1;

        while (true)
        {
            right = push_right(nums, right, val);
            if (left < right)
            {
                if (nums[left] == val)
                {
                    swap(nums[left], nums[right]);
                    right--;
                    count++;
                }
                left++;
            }
            else 
            {
                break;
            }
        }
        return nums.size() - count;
    }

    int push_right(vector<int>& nums, int right, int val)
    {
        while(right >= 0)
        {
            if (nums[right] == val)
            {
                right--;
                count++;
            }
            else
            {
                break;
            }
        }
        return right;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> input = {0, 1, 2, 2, 3, 0, 4, 2};
    s.removeElement(input, 2);
    return 0;
}

