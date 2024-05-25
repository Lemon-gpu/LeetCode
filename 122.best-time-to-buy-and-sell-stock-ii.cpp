/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include "General.h"

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int prev = -1;
        for (int i: prices)
        {
            if (prev == -1)
            {
                prev = i;
                continue;
            }
            int currProfit = i - prev;
            if (currProfit > 0)
            {
                profit += currProfit;
            }
            prev = i;
        }
        return profit;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices);
    return 0;
}

