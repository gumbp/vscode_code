/*
 * @Author: Mr.Gan
 * @Date: 2023-09-16 10:12:17
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-16 19:01:38
 */
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
// @lc code=start
#include <stack>
using namespace std;
class MyQueue
{
private:
    stack<int> st_in;
    stack<int> st_out;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        st_in.push(x);
    }

    int pop()
    {
        if (st_out.empty())
        {
            while (!st_in.empty())
            {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        int value = st_out.top();
        st_out.pop();
        return value;
    }

    int peek()
    {
        if (st_out.empty())
        {
            while (!st_in.empty())
            {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        return st_out.top();
    }

    bool empty()
    {
        if (st_in.empty() && st_out.empty())
        {
            return true;
        }
        return false;
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