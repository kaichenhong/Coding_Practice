/*
 *  Results:    AC (11 ms [97.03%];  11.3 MB [95.66%])
 */


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *head_new = nullptr, *iter = head;
        ListNode *front = head, *end = nullptr;
        ListNode *begin = head, *prev = nullptr;

        if (k == 1)
            return head;

        while (true) {
            for (int i = 0; i < k; ++i) {
                if (iter == nullptr)
                    return (head_new != nullptr) ? head_new : head;
                iter = iter->next;
            }

            end = iter;
            begin = front;
            for (int i = 0; i < k; ++i) {
                auto *temp = front->next;
                front->next = end;
                end = front;
                front = temp;
            }

            if (__builtin_expect(!!(prev == nullptr), 0))
                prev = head;
            else {
                prev->next = end;
                prev = begin;
            }
            if (__builtin_expect(!!(head_new == nullptr), 0))
                head_new = end;
        }
    }
};

