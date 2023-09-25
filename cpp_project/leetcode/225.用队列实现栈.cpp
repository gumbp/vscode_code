/*
 * @Author: Mr.Gan
 * @Date: 2023-09-16 19:03:36
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-16 20:50:16
 */
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
// @lc code=start
#include <queue>
using namespace std;
class MyStack
{
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    MyStack()
    {}

    void push(int x)
    {
        queue1.push(x);
    }

    int pop()
    {
        int size = queue1.size();
        //size先减l是为了留下最后一个元素
        if(size<1){
           return  1;
        }
        size--;
        while(size--){
            queue2.push(queue1.front());
            queue1.pop();
        }
        int value =queue1.front();
        queue1.pop();
        //恢复出栈后的剩余元素
        queue1 = queue2;
        //清空备份队列  防止信息冗余
        queue2=queue<int>();
        return value;
    }

    int top()
    {
        return queue1.back();
    }

    bool empty()
    {
        if(queue1.empty())
        {
            return true;
        }
        return false;
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