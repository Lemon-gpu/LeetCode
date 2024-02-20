/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */
#include "General.h"

// @lc code=start
class Solution {
private:
    unordered_map<int, int> buckets; // 用于存储水果类型和数量的哈希表

    // 减少指定类型的水果数量，并在数量为0时从哈希表中删除该类型
    int minus(int type)
    {
        buckets[type]--;
        if (buckets[type] <= 0) { buckets.erase(type); }
        return buckets.size(); // 返回当前哈希表中不同类型水果的数量
    }

    // 检查是否满足放入新水果的条件
    bool check_availability(int type)
    {
        bool flag = false;
        if ((buckets.size() <= 1) || 
            (buckets.size() <= 2 && buckets.find(type) != buckets.end())) { flag = true; }
        return flag; // 返回是否可以放入新水果的标志
    }

public:
    // 计算最多可以收集的水果数量
    int totalFruit(vector<int> fruits) 
    {
        int result = INT_MIN; // 最终结果
        int left = 0; // 滑动窗口的左边界

        for (int i = 0; i < fruits.size(); i++)
        {
            int type = fruits[i]; // 当前水果的类型

            if (check_availability(type) == true) // 检查是否可以放入新水果
            {
                buckets[type]++; // 哈希表中对应类型的水果数量加1
                result = max(result, i - left + 1); // 更新最大收集数量
            }
            else // 当无法放入新水果时
            {
                for (left; left <= i;) // 从左边界开始逐个减少水果数量，直到满足放入新水果的条件
                {
                    int temp = minus(fruits[left]); // 减少左边界对应类型的水果数量
                    left++; // 左边界右移
                    if (temp < 2) { i--; break; } // 如果减少后的不同类型水果数量小于2，则需要重新判断当前水果是否可以放入
                }
            }
        }

        return result; // 返回最多可以收集的水果数量
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.totalFruit({1, 2, 3, 2, 2, 1});
    return 0;
}


