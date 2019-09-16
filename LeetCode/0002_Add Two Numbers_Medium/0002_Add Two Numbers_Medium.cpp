/**
 *  LeetCode: 2. Add Two Numbers (Medium)
 *
 *      You are given two non-empty linked lists representing two non-negative integers. 
 *
 *      The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 *      You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *
 *      Example:    1. (2 -> 4 -> 3) + (5 -> 6 -> 4) => (7 -> 0 -> 8);
 *                      Explanation: 342 + 465 = 807.
 *
 *
 *  Results:    AC (16 ms [97.56%];  10.6 MB [5.71%])
 *              AC (20 ms [88.03%];  10.1 MB [93.14%])
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersSolver(l1, l2, 0);
    }

private:
    ListNode* addTwoNumbersSolver(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && !carry)   return NULL;

        if (!carry && (!l1 != !l2))   // !l1 != !l2 == l1 XOR l2
            return !l1 ? l2 : l1;
        else {
            int sum = (!l1 ? 0 : l1->val) + (!l2 ? 0 : l2->val) + carry;
            ListNode *node = new ListNode(sum%10);
            node->next = addTwoNumbersSolver((!l1 ? NULL : l1->next), (!l2 ? NULL : l2->next), sum/10);
            return node;
        }
    }
};


/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2)   return NULL;
        
        int carry = 0, sum = 0;
        ListNode *head = new ListNode(0);
        head->val = (l1->val + l2->val) % 10;
        carry = (l1->val + l2->val) / 10;
        ListNode *l1ptr = l1, *l2ptr = l2, *ptr = head;
        while (l1ptr->next && l2ptr->next) {
            l1ptr = l1ptr->next;
            l2ptr = l2ptr->next;
            ptr->next = new ListNode(0);
            ptr = ptr->next;
            ptr->val = (l1ptr->val + l2ptr->val + carry) % 10;
            carry = (l1ptr->val + l2ptr->val + carry) / 10;
        }
        if (l1ptr->next) {
            ptr->next = l1ptr->next;
        }
        else if (l2ptr->next) {
            ptr->next = l2ptr->next;
        }

        while (carry) {
            if (!ptr->next) {
                ptr->next = new ListNode(carry);
                carry = 0;
            }
            else {
                ptr = ptr->next;
                int buf = ptr->val;
                ptr->val = (buf + carry) % 10;
                carry = (buf + carry) / 10;
            }
        }
        return head;
    }
};*/