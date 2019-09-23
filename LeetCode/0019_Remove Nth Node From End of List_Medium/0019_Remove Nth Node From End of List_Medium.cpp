/**
 *  LeetCode: 19. Remove Nth Node From End of List (Medium)
 *
 *     Given a linked list, remove the n-th node from the end of list and return its head.
 * 
 *     Note: Given n will always be valid.      Follow up: Could you do this in one pass?
 *
 *
 *
 *      Example:    1. 1->2->3->4->5, and n = 2 => 1->2->3->5;
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.6 MB [61.84%])
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        return solver(head, n);
    }

private:
    int counter = 0;
    ListNode* solver(ListNode *ptr, int &n) {
        if (ptr == NULL) {
            counter++;
            return ptr;
        }

        ptr->next = solver(ptr->next, n);
        if (counter == n) {
            counter++;
            return ptr->next;
        }
        counter++;
        return ptr;
    }
};