/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include "General.h"

// @lc code=start
class MyQueue
{
private:
    stack<int> front;
    stack<int> back;
    int curr_pointer = 0; // 0 is front and 1 is back.

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        this->front.push(x);
    }

    int pop()
    {
        int result = this->peek();
        back.pop();
        return result;
    }

    int peek()
    {
        int result = 0;
        if (this->back.empty())
        {
            while (!this->front.empty())
            {
                back.push(front.top());
                front.pop();
            }
        }
        result = back.top();
        return result;
    }

    bool empty()
    {
        return this->front.empty() && this->back.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
