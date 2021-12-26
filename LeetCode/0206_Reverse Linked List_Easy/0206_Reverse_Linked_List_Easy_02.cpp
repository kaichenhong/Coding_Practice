/**
 *  LeetCode: 206. Reverse Linked List (Easy)
 *
 *      Reverse a singly linked list.
 *
 *
 *      Example:    1. 1->2->3->4->5->NULL => 5->4->3->2->1->NULL.
 *
 *
 *
 *  Results:    AC (4 ms [95.84%];  8.5 MB [9.93%])
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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> buf;
        ListNode *ptr = head;

        if (head == NULL)
            return NULL;

        while (head) {
            buf.push(head);
            head = head->next;
        }

        ptr = buf.top();
        head = buf.top();
        while (!buf.empty()) {
            ptr->next = buf.top();
            ptr = ptr->next;
            buf.pop();
        }
        ptr->next = NULL;

        return head;
    }
};

