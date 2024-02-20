/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include "General.h"

// @lc code=start
class Solution
{
private:
    stack<int> nums;
    enum Type
    {
        Number,
        Signal
    };
    int cal(int a, int b, string signal)
    {
        if (signal == "+")
            return a + b;
        if (signal == "-")
            return a - b;
        if (signal == "*")
            return a * b;
        if (signal == "/")
            return a / b;
        return 0;
    }
    Type classification(string s)
    {
        if (s.size() >= 2 || (s[0] >= '0' && s[0] <= '9'))
        {
            return Number;
        }
        return Signal;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        for (string s : tokens)
        {
            switch (classification(s))
            {
            case Number:
                nums.push(stoi(s));
                break;
            case Signal:
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(cal(a, b, s));
                break;
            }
        }
        int result = nums.top();
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = solution.evalRPN(tokens);
    cout << "Result: " << result << endl;

    return 0;
}
