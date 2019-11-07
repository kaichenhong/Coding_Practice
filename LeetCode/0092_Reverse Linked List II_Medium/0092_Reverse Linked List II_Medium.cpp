/**
 *  LeetCode: 92. Reverse Linked List II (Medium)
 *
 *     Reverse a linked list from position m to n. Do it in one-pass.
 * 
 *     Note: 1 ≤ m ≤ n ≤ length of list.
 *
 *
 *
 *      Example:    1. 1->2->3->4->5->NULL, m = 2, n = 4 => 1->4->3->2->5->NULL;
 *
 *
 *  Results:    AC (0 ms [100.00%]; 8.6 MB [93.75%])
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m == n)   return head;

		ListNode *buffPtr = NULL, *rearPtr = NULL, *curPtr = head, *prevPtr = NULL, *nextPtr = NULL;
        int counter = 0;
        while (true) {
            counter++;
            //printf("%d\n", counter);
            if (counter == m-1) {
                buffPtr = curPtr;
                //cout << "buffPtr->val = " << buffPtr->val << "\n";
                curPtr = curPtr->next;
            }
            else if (counter == m) {
                prevPtr = curPtr;
                rearPtr = curPtr;
                //cout << rearPtr << endl;
                curPtr = curPtr->next;
            }
            else if (counter > m && counter <= n) {
                nextPtr = curPtr->next;
                curPtr->next = prevPtr;
                prevPtr = curPtr;
                curPtr = nextPtr;
            }
            else if (counter > n) {
                if (buffPtr == NULL) 
                    head = prevPtr;
                else
                    buffPtr->next = prevPtr;

                //cout << rearPtr << endl;
                rearPtr->next = curPtr;
                break;
            }
            else {
                curPtr = curPtr->next;
            }
        }
        return head;
    }
};