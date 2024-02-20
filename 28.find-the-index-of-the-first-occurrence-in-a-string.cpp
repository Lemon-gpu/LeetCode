/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */
#include "General.h"

// @lc code=start
class Solution
{
private:
    vector<int> lps; // 这里面存储的是base-0情况下，如果当前字符不匹配，可以直接进行下一步搜索的索引
    void generateLps(string pattern)
    {
        this->lps = vector<int>(pattern.size(), 0);
        int len = 0;

        for (int i = 1; i < pattern.size(); i++)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                this->lps[i] = len;
            }
            else // pattern[i] != pattern[len]
            {
                while (len > 0 && pattern[i] != pattern[len])
                {
                    len = lps[len - 1];
                }
                if (pattern[i] == pattern[len]) // It is possible that len == 0 or pattern[i] == pattern[len]. In the latter case we need to add len.
                {
                    len++;
                }
                this->lps[i] = len;
            }
        }
    }

public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        if (needle.size() == 0)
        {
            return 0;
        }

        int result = -1;
        int j = 0;
        this->generateLps(needle);
        for (int i = 0; i < haystack.size(); i++)
        {
            if (j < needle.size() && haystack[i] == needle[j])
            {
                j++;
                if (j == needle.size()) // 搜索完毕
                {
                    result = i - j + 1;
                    break;
                }
            }
            else
            {
                if (j != 0)
                {
                    j = this->lps[j - 1];
                    i--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.strStr("aabaaabaaac", "aabaaac");
    return 0;
}
