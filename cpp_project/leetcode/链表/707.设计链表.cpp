// @before-stub-for-debug-begin
#include "commoncppproblem707.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
// @lc code=start
class MyLinkedList
{
public:
    struct LinkNode
    {
        int val;
        struct LinkNode *next;
        /* data */
        LinkNode(int x) : val(x), next(nullptr) {}
        LinkNode() : val(0), next(nullptr) {}
        LinkNode(int x, LinkNode *next) : val(x), next(next) {}
    };

    MyLinkedList()
    {
        number_of_nodes = 0;
    }

    int get(int index)
    {
        if (index < 0 || index > (number_of_nodes - 1))
        {
            return -1;
        }
        LinkNode *cur = new LinkNode();
        virtual_head->next = cur;
        while (index - 1)
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkNode *newNode = new LinkNode(val);
        newNode->next = virtual_head->next;
        virtual_head->next = newNode;
        number_of_nodes++;
    }

    void addAtTail(int val)
    {
        LinkNode *head = virtual_head->next;
        while (head->next != nullptr)
        {
            head = head->next;
        }
        LinkNode *temp = new LinkNode(val);
        head->next = temp;
        number_of_nodes++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > number_of_nodes - 1)
        {
            return;
        }
        LinkNode *new_node = new LinkNode(val);
        LinkNode *head = virtual_head->next;
        if (index == number_of_nodes)
        {
            while (head->next != nullptr)
            {
                head = head->next;
            }
            head->next = new_node;
            number_of_nodes++;
        }
        else
        {
            while ((index - 1))
            {
                head = head->next;
                index--;
            }
            new_node->next = head->next;
            head->next = new_node;
            number_of_nodes++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > (number_of_nodes - 1))
        {
            return;
        }
        LinkNode *head = virtual_head->next;
        while (index - 1)
        {
            head = head->next;
            index--;
        }
        head->next = head->next->next;
        number_of_nodes--;
    }

private:
    int number_of_nodes;
    LinkNode *virtual_head = new LinkNode(-1);
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end