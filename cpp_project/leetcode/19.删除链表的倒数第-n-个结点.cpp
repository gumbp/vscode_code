/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr||head->next==nullptr){
            return nullptr;
        }
        ListNode *p = head;
        ListNode *pre_head = new ListNode(-1);
        pre_head->next = head;
        while(n){
            head = head->next;
            n--;
        }
        if(head==nullptr){
            return p->next;
        }
        while(head->next){
            head = head->next;
            p = p->next;
        }
        p->next = p->next->next;
        return pre_head->next;
    }
};
// @lc code=end

