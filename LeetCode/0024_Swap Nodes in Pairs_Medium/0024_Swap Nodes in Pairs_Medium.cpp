/**
 *  LeetCode: 24. Swap Nodes in Pairs (Medium)
 *
 *     Given a linked list, swap every two adjacent nodes and return its head. You may not modify the values in the list's nodes, only nodes itself may be changed.
 * 
 *     Note: Given n will always be valid.      Follow up: Could you do this in one pass?
 *
 *
 *
 *      Example:    1. 1->2->3->4 => 2->1->4->3;
 *
 *
 *  Results:    AC (0 ms [100.00%];  8.6 MB [85.71%])
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
    ListNode* swapPairs(ListNode* head) {
        return solver(head);
    }

private:
    ListNode* solver(ListNode *ptr) {
        if (ptr == NULL || ptr->next == NULL) {
            return ptr;
        }

        ListNode *temp = ptr->next;
        ptr->next = solver(ptr->next->next);
        temp->next = ptr;
        return temp;
    }
};

/*class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode *ptr = solver(head);
        if (stage == 2) {
            stage = 1;
            ptr->next = tmp->next;
            tmp->next = ptr;
            ptr = tmp;
        }
        return ptr;
    }

private:
    int stage = 0;
    ListNode *tmp = NULL;
    ListNode* solver(ListNode *ptr) {
        if (ptr->next == NULL || ptr->next->next == NULL) {
            stage++;
            return ptr;
        }

        ptr->next = solver(ptr->next);
        if (stage == 1) {
            stage++;
            tmp = ptr->next;
        }
        else if (stage == 2) {
            stage = 1;
            ptr->next->next = tmp->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
        }

        return ptr;
    }
};
//  error: 1->2->3 => 1->3->2 (X), 2->1->3 (O).
*/