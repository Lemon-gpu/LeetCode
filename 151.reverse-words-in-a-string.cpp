/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include "General.h"
// @lc code=start
class Solution
{
private:
    void preProcess(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch)
                                        { return !std::isspace(ch); }));

        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch)
                             { return !std::isspace(ch); })
                    .base(),
                s.end());
        reverse(s.begin(), s.end());
    }

public:
    string reverseWords(string s)
    {
        this->preProcess(s);
        int left = 0;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (s[i] == ' ')
            {
                if (s[left] == ' ')
                {
                    s.erase(s.begin() + left);
                    size--;
                    i--;
                    left = i;
                }
                else
                {
                    reverse(s.begin() + left, s.begin() + i);
                    left = i;
                }
            }
            else
            {
                if (s[left] == ' ')
                {
                    left = i;
                }
                else
                {
                    if (i == s.size() - 1)
                    {
                        reverse(s.begin() + left, s.end());
                    }
                }
            }
        }
        return s;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    string input = "a good   example";
    string result = solution.reverseWords(input);
    cout << result << endl;

    return 0;
}
