/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr){
            return NULL;
        }
        ListNode *virtual_head = new ListNode(-1);
        virtual_head->next = head;
        ListNode *prehead = virtual_head;
        while(head)
        {
         if(head->val==val){
            prehead->next = head->next;
            head = head->next;
         }   
         else{
            prehead = head;
            head = head->next;
         }
        }
        return virtual_head->next;
    }
};
// @lc code=end

