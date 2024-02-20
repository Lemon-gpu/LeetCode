/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    bool nums1[1100] = {};
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = {};
        for (int i: nums1)
        {
            this->nums1[i] = 1;
        }

        for (int i: nums2)
        {
            if (this->nums1[i])
            {
                result.push_back(i);
                this->nums1[i] = 0;
            }
        }

        return result;

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


