/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] Assign Cookies
 */
#include "General.h"

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;

        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                break;
            }
            if (s[s.size() - 1] >= g[i])
            {
                result++;
                s.pop_back();
            }
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    Solution so;
    cout << so.findContentChildren(g, s) << endl;
    return 0;
}
