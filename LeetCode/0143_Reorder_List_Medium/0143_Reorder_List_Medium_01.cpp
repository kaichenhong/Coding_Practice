/*
 *  Results:    AC (28 ms [99.28%];  19 MB [9.65%])
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
    void reorderList(ListNode* head) {
        vector<ListNode*> buf;

        while (head) {
            buf.push_back(head);
            head = head->next;
        }

        head = buf[0];
        for (int i = 1; i < buf.size(); ++i) {
            if (i % 2 == 0)
                head->next = buf[i/2];
            else
                head->next = buf[buf.size() - i/2 - 1];

            head = head->next;
        }
        head->next = NULL;

        head = buf[0];
    }
};

