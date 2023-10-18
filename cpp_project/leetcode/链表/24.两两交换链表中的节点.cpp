// @before-stub-for-debug-begin
#include "commoncppproblem24.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *pre_head = new ListNode(-1);
        pre_head->next = head;

        ListNode *p = head;
        // pre用于指向已两两交换的结点的后一个结点
        ListNode *pre = pre_head;

        ListNode *a = nullptr;
        ListNode *b = nullptr;
        //防止空指针异常
        while (p != nullptr && p->next != nullptr)
        {
            ListNode *temp = p->next->next;
            a = p;
            b = p->next;
            pre->next = b;
            b->next = a;
            pre = a;
            a->next = p->next->next;
            p = temp;
        }
        if (p)
        {
            pre->next = p;
            p->next = nullptr;
        }
        else
        {
            pre->next = nullptr;
        }
        return pre_head->next;
    }
};
// @lc code=end
