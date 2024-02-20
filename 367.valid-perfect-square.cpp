/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

#include "General.h"

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 1;
        int right = num;
        bool flag = false;
        while (right >= left)
        {
            long long mid = left + ((right - left) >> 1);
            long long times = mid * mid;
            if (times == num)
            {
                flag = true;
                break;
            }
            else
            {
                if (times > num)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return flag;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    cout << s.isPerfectSquare(14);
    return 0;
}
