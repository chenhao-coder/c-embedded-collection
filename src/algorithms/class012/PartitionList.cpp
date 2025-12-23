#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution {
public:
    static ListNode* PartitionList(ListNode* head, int x) {
        ListNode* leftHead = nullptr;
        ListNode* leftTail = nullptr;
        ListNode* rightHead = nullptr;
        ListNode* rightTail = nullptr;

        while(head != nullptr) {
            ListNode* next = head->next;
            head->next = nullptr;
            
            if(head->val < x) {
                if(leftHead == nullptr) {
                    leftHead = head;
                } else {
                    leftTail->next = head;
                }
                leftTail = head;
            } else {
                if(rightHead == nullptr) {
                    rightHead = head;
                } else {
                    rightTail->next = head;
                }
                rightTail = head;
            }

            head = next;
        }

        if(leftHead == nullptr) {
            return rightHead;
        }
        leftTail->next = rightHead;

        return leftHead;
    }
};