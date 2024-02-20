/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
/**
 * @brief Solution类表示LeetCode上“最小窗口子串”问题的解决方案。
 * 
 * 该类提供了一种在给定字符串中查找包含另一个给定字符串的最小窗口子串的方法。
 */
class Solution
{
private:
    enum Boundary
    {
        LEFT, // 左边界
        RIGHT // 右边界
    };
    unordered_map<char, int> target; // 目标字符及其频率的映射

    /**
     * @brief 使用目标字符串初始化目标映射。
     * 
     * @param t 目标字符串。
     */
    void init_target(string t)
    {
        for (char c : t)
        {
            target[c]++;
        }
    }

    /**
     * @brief 返回当前结果和目标字符串之间的最小字符串。
     * 
     * @param result 当前结果字符串。
     * @param target 目标字符串。
     * @return string 最小字符串。
     */
    string min_string(string result, string target)
    {
        if (result != "" && result.size() <= target.size())
        {
            return result;
        }
        return target;
    }

    /**
     * @brief 根据当前状态（左边界或右边界）验证字符。
     * 
     * @param c 要验证的字符。
     * @param state 当前边界状态。
     * @return true 如果字符有效。
     * @return false 如果字符无效。
     */
    bool validation(char c, Boundary state)
    {
        bool flag = true;
        if (target.find(c) != target.end())
        {
            switch (state)
            {
            case LEFT:
                target[c]++;
                break;
            case RIGHT:
                target[c]--;
                break;
            }
        }
        for (const auto &pair : target)
        {
            if (pair.second > 0)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }

public:
    /**
     * @brief Finds the minimum window substring in the given string that contains all the characters from the target string.
     * 
     * @param s The given string.
     * @param t The target string.
     * @return string The minimum window substring.
     */
    string minWindow(string s, string t)
    {
        init_target(t);
        int left = 0;
        string result_str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (validation(s[i], RIGHT) == true)
            {
                for (left; left <= i; left++) 
                {
                    if (validation(s[left], LEFT) != true)
                    {
                        result_str = min_string(result_str, s.substr(left, i - left + 1));
                        left++;
                        break;
                    }
                }
            }
        }
        return result_str;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "a";
    string t = "aa";
    string result = solution.minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;
    return 0;
}
