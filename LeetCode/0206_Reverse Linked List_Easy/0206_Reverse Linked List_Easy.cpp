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
 *  Results:    AC (4 ms [98.94%];  9 MB [100.00%])
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = 0, *temp = 0;
        while (head != 0) {
            temp = head;
            head = head->next;
            temp->next = curr;
            curr = temp;
        }
        return curr;
    }
};