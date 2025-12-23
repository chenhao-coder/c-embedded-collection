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
    static ListNode* AddTwoNumbers(ListNode* h1, ListNode* h2) {
        ListNode* ans = nullptr;
        ListNode* cur = nullptr;
        int carry = 0;

        for(int sum, val; 
            h1 != nullptr || h2 != nullptr; 
            h1 == nullptr ? nullptr : h1->next, h2 ==nullptr ? nullptr :  h2->next) {
            
            sum = (h1 == nullptr ? 0 : h1->val) + (h2 == nullptr ? 0 : h2->val) + carry;
            val = sum % 10;
            carry = sum / 10;

            if(ans == nullptr) {
                ans = new ListNode(val);
                cur = ans;
            } else {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }

        if(carry == 1) {
            cur->next = new ListNode(carry);
        }

        return ans;
    }
};