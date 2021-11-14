/**
 *  LeetCode: 21. Merge Two Sorted Lists (Easy)
 *
 *      Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
 *
 *
 *      Example :
 *          Input: l1 = [1,2,4], l2 = [1,3,4]
 *          Output: [1,1,2,3,4,4]
 *
 *          Input: l1 = [], l2 = []
 *          Output: []
 *
 *          Input: l1 = [], l2 = [0]
 *          Output: [0]
 *
 *
 *      Constraints:
 *          The number of nodes in both lists is in the range [0, 50].
 *          -100 <= Node.val <= 100
 *          Both l1 and l2 are sorted in non-decreasing order.
 *
 *  Results:    AC (4 ms [95.33%]; 14.9 MB [54.02])
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	/* a pointer for moving nodes to return */
        ListNode *res = NULL, *res_head = NULL;

        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;


	/* determin first ListNode */
        if (l1->val < l2->val) {
            res = l1;
            l1 = l1->next;
        } else {
            res = l2;
            l2 = l2->next;
        }
        res_head = res;

	/* check nodes one by one and throw it to res->next */
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
            } else {
                res->next = l2;
                l2 = l2->next;
            }

            res = res->next;
        }

	/* check remain nodes */
        if (l1)
            res->next = l1;
        if (l2)
            res->next = l2;


        return res_head;
    }
};
