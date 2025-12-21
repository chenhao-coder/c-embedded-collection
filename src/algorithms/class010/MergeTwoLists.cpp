#include <iostream>

using namespace std;

// 将两个升序链表合并为一个新的 升序 链表并返回
// 新链表是通过拼接给定的两个链表的所有节点组成的
// 测试链接 : https://leetcode.cn/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr || list2 == nullptr) {
            return list1 == nullptr ? list2 : list1;
        }
        
        ListNode* head = (list1->val <= list2->val ? list1 : list2);
        ListNode* cur1 = head->next;
        ListNode* cur2 = (head == list1 ? list2 : list1);
        ListNode* pre = head;

        while(cur1 != nullptr && cur2 != nullptr) {
            if(cur1->val <= cur2->val) {
                pre->next = cur1;
                cur1 = cur1->next;
            } else {
                pre->next = cur2;
                cur2 = cur2->next;
            }

            pre = pre->next;
        }

        pre->next = (cur1 == nullptr ? cur2 : cur1);

        return head;
    }
};