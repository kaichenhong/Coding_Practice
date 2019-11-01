/**
 *  LeetCode: 86. Partition List (Medium)
 *
 *      Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 *      You should preserve the original relative order of the nodes in each of the two partitions.
 *
 *
 *
 *      Example:    1.  head = 1->4->3->2->5->2, x = 3  =>  1->2->2->4->3->5
 *
 *
 *
 *  Results:    AC (4 ms [97.1%];  8.6 MB [91.67%])
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;

        ListNode *newHead = new ListNode(INT_MIN);
        ListNode *cur = newHead;
        newHead->next = head;

        ListNode *buffer = new ListNode(INT_MIN);
        ListNode *buf = buffer;

        while (cur->next != NULL) {
            if (cur->next->val < x) {
                buf->next = cur->next;
                buf = buf->next;

                cur->next = cur->next->next;
                buf->next = NULL;
            }
            else {
                cur = cur->next;
            }
        }
        buf->next = newHead->next;
        head = buffer->next;

        delete newHead;
        delete buffer;
        return head;
    }
};