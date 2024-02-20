/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

#include "General.h"

// @lc code=start
class Solution
{
private:
    vector<int> state = vector<int>(26, 0);
    vector<int> target = vector<int>(26, 0);

    bool equal()
    {
        return state == target;
    }

    void nextStep(const string& s, int index, int lengthOfTarget)
    {
        if (index == 0)
        {
            for (index; index < lengthOfTarget; index++)
            {
                char curr = s[index];
                state[curr - 'a']++;
            }
            return;
        }
        char pre = s[index - 1];
        char next = s[index + lengthOfTarget - 1];
        state[pre - 'a']--;
        state[next - 'a']++;
    }

    void initTarget(const string& p)
    {
        for (char c : p)
        {
            target[c - 'a']++;
        }
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        initTarget(p);
        vector<int> result; 
        int times = int(s.length()) - int(p.length()) + 1;
        for (int i = 0; i < times; i++)
        {
            nextStep(s, i, p.length());
            if (equal())
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "aa";
    string p = "aaaaa";
    vector<int> result = solution.findAnagrams(s, p);
    cout << "Indices of anagrams: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
