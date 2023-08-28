// @before-stub-for-debug-begin
#include "commoncppproblem2.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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


//遍历了链表 时间复杂度为O(n),未使用额外空间，只是不断修改结点指向，故空间复杂度为O(1)
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 若某个链表为空  直接返回
        if (l1 == nullptr || l2 == nullptr)
        {
            return l1 == nullptr ? l2 : l1;
        }
        ListNode *p = l1;                 // p为工作指针
        ListNode *sum = new ListNode(-1); // 定义合并链表的头指针  不存储数据
        sum->next = p;
        ListNode *pre_node = sum;
        int m = 0; // m表示低位相加结果的进位
        int n = 0;//表示低位相加的结果模10的余数
        // 当一个链表走完时，结束两两相加
        while ((l1 != nullptr) && (l2 != nullptr))
        {
            n= (l1->val + l2->val + m) % 10;
            m = (l1->val + l2->val + m) / 10; // 保存本次运算的进位结果（1或0）
            p->val = n;
            l1 = l1->next;
            l2 = l2->next;
            // 记录前一个结点地址 以便操作
            pre_node = p;
            p = p->next;
        }
        // 当l1 l2链表长度相等
        if ((l1 == nullptr) && (l2 == nullptr))
        {
            // 有进位时
            if (m)
            {
                ListNode *temp = new ListNode(0);
                temp->val = m;
                pre_node->next = temp;
                return sum->next;
            }
            // 无进位 直接返回
            else
            {
                return sum->next;
            }
        }

        // 链表长度不一致时 找出较长者
        p = ((l1 == nullptr) ? l2 : l1);
        while (p != nullptr)
        {
            n= (p->val + m) % 10;
            m = (p->val + m) / 10;
            p->val = n;
            pre_node->next = p;
            pre_node= p;
            p = p->next;
        }

        if (m)
        {
            // 最后结点运算有进位  则再创一个新结点存储进位值
            ListNode *temp = new ListNode(0);
            temp->val = m;
            pre_node->next = temp;
        }
        return sum->next;
    }
};

// @lc code=end
