/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 4Sum II
 */

#include "General.h"

// @lc code=start
/**
 * @brief The Solution class represents a solution for the problem of finding the number of quadruplets
 *        from four given arrays whose sum is equal to zero.
 */
class Solution {
private:
    /**
     * @brief group calculates the frequency of sums of all possible pairs from two given arrays.
     * @param nums1 The first array.
     * @param nums2 The second array.
     * @return An unordered map where the key is the sum of two elements and the value is the frequency of that sum.
     */
    unordered_map<int, int> group(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> result;
        for (int i: nums1)
        {
            for (int j: nums2)
            {
                result[i + j]++;
            }
        }
        return result;
    }
public:
    /**
     * @brief fourSumCount calculates the number of quadruplets from four given arrays whose sum is equal to zero.
     * @param nums1 The first array.
     * @param nums2 The second array.
     * @param nums3 The third array.
     * @param nums4 The fourth array.
     * @return The number of quadruplets whose sum is equal to zero.
     */
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int, int> sum1 = group(nums1, nums2);
        unordered_map<int, int> sum2 = group(nums3, nums4);
        int result = 0;

        for (pair<int, int> p1: sum1)
        {
            auto p2 = sum2.find(0 - p1.first);
            if (p2 != sum2.end())
            {
                result += (p1.second * p2->second);
            }
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    int result = solution.fourSumCount(nums1, nums2, nums3, nums4);
    cout << "Result: " << result << endl;

    return 0;
}


