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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = new ListNode(); // p为工作指针
        ListNode *sum = p;
        ListNode *Pre_node = nullptr;
        int m = 0; // m表示低位相加结果的进位
        // 当一个链表走完时，结束两两相加
        while ((l1 != nullptr) && (l2 != nullptr))
        {
            p->val = (l1->val + l2->val + m) % 10;
            p->next = new ListNode();         // 开辟下一个节点的内存空间
            m = (l1->val + l2->val + m) / 10; // 保存本次运算的进位结果（1或0）
            l1 = l1->next;
            l2 = l2->next;
            //记录倒数第二个节点地址 以便操作
            Pre_node = p;
            p = p->next;
        }
        // 当l1 l2链表长度相等
        if ((l1 == nullptr) && (l2 == nullptr))
        {
            //有进位时
            if (m)
            {
                p->val += m;
                return sum;
            }
            else
            {
                // 删除分配的冗余结点
                Pre_node->next= nullptr;
                delete p;
                return sum;
            }
        }

        // 链表长度不一致时 找出较长者
        ListNode *temp = (l1 ? l1 : l2);
        while (temp != nullptr)
        {
            p->val = (temp->val + m) % 10;
            m = (temp->val + m) / 10;
            p->next = new ListNode();

            temp = temp->next;
            Pre_node = p;
            p = p->next;
        }

        if (m)
        {
            p->val = m;
        }
        else
        {
            Pre_node->next = nullptr;
            delete p;
        }
        return sum;
    }
};
// @lc code=end
