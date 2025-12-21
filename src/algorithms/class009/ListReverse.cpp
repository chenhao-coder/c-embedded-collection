#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};

// 反转单链表测试链接 : https://leetcode.cn/problems/reverse-linked-list/
ListNode* revertList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* next = nullptr;

    while(head != nullptr) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

struct DoubleListNode {
    int val;
    DoubleListNode* last;
    DoubleListNode* next;

    DoubleListNode(int v) : val(v), last(nullptr), next(nullptr) {}
};

DoubleListNode* revertDoubleList(DoubleListNode* head) {
    DoubleListNode* pre = nullptr;
    DoubleListNode* next = nullptr;

    while(head != nullptr) {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }
    return pre;
}