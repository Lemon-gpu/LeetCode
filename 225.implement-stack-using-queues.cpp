/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

#include "General.h"

// @lc code=start
class MyStack
{
private:
    queue<int> sim;

public:
    MyStack()
    {
        sim.push(-1);
    }

    void push(int x)
    {
        sim.push(x);
    }

    int pop()
    {
        int tmp = sim.front();
        sim.pop();
        while (sim.front() != -1)
        {
            sim.push(tmp);
            tmp = sim.front();
            sim.pop();
        }
        return tmp;
    }

    int top()
    {
        int top = this->pop();
        this->push(top);
        return top;
    }

    bool empty()
    {
        return sim.size() == 1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
