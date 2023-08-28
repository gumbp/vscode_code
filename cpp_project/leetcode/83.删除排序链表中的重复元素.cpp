/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *virtual_head = new ListNode(-1);
        virtual_head->next = head;
        ListNode *p = head->next;
        ListNode *preHead = virtual_head;
        while (head != nullptr && head->next != nullptr)
        {
            if (p && head->val == p->val)
            {
                p = p->next;
                continue;
            }
            // p未移动时
            if (head->next == p)
            {
                preHead=head;
                head = p;
                if (p != nullptr)
                {
                    p = p->next;
                }
            }
            else
            {
                preHead=head;
                head = p;
                preHead->next = head;
                if (p != nullptr)
                {
                    p = p->next;
                }
            }
        }

        return virtual_head->next;
    }
};
// @lc code=end
