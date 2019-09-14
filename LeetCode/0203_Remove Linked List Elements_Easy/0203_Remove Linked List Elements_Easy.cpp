/**
 *  LeetCode: 203. Remove Linked List Elements (Easy)
 *
 *      Remove all elements from a linked list of integers that have value val.
 *
 *
 *      Example:    1. 1->2->6->3->4->5->6, val = 6 => 1->2->3->4->5.
 *
 *
 *
 *  Results:    AC (24 ms [94.80%];  11 MB [71.70%])
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
    ListNode* removeElements(ListNode* head, int val) {        
        while (head != 0 && head->val == val) {
            head = head->next;
        }

        ListNode *curr = head;
        while (curr != 0 && curr->next != 0) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};