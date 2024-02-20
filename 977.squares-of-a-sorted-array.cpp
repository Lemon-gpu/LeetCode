/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

#include "General.h"

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int split_index = findSplitIndex(nums);
        vector<int> left_nums = getLeftNums(nums, split_index);
        vector<int> right_nums = getRightNums(nums, split_index);

        squareElements(left_nums);
        squareElements(right_nums);

        mergeSortedArrays(left_nums, right_nums, nums);

        return nums;
    }

private:
    int findSplitIndex(const vector<int> &nums)
    {
        int split_index = 0;
        for (int num : nums)
        {
            if (num >= 0)
            {
                break;
            }
            split_index++;
        }
        return split_index;
    }

    vector<int> getLeftNums(const vector<int> &nums, int split_index)
    {
        vector<int> left_nums(nums.begin(), nums.begin() + split_index);
        reverse(left_nums.begin(), left_nums.end());
        return left_nums;
    }

    vector<int> getRightNums(const vector<int> &nums, int split_index)
    {
        return vector<int>(nums.begin() + split_index, nums.end());
    }

    void squareElements(vector<int> &nums)
    {
        for_each(nums.begin(), nums.end(), [](int &n)
                 { n *= n; });
    }

    void mergeSortedArrays(const vector<int> &left_nums, const vector<int> &right_nums, vector<int> &nums)
    {
        int left = 0;
        int right = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (left >= left_nums.size())
            {
                for (right; right < right_nums.size(); right++)
                {
                    nums[i] = right_nums[right];
                    i++;
                }
                break;
            }
            if (right >= right_nums.size())
            {
                for (left; left < left_nums.size(); left++)
                {
                    nums[i] = left_nums[left];
                    i++;
                }
                break;
            }

            if (left_nums[left] < right_nums[right])
            {
                nums[i] = left_nums[left];
                left++;
            }
            else
            {
                nums[i] = right_nums[right];
                right++;
            }
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> result = s.sortedSquares({-4, -1, 0, 3, 10});
    return 0;
}

