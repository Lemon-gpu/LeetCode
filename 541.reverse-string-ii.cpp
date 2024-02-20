/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] Reverse String II
 */

#include "General.h"

// @lc code=start
class Solution {
private:
    void reverse(string& s, int index, int size)
    {
        int left = index;
        int right = index + size - 1;
        while (right > left)
        {
            swap(s[left++], s[right--]);
        }
    }
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k >= s.size())
            {
                reverse(s, i, s.size() - i);
            }
            else
            {
                reverse(s, i, k);
            }
        }
        return s;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string st = "abcd";
    int k = 4;
    cout << s.reverseStr(st, k) << endl;
    return 0;
}

