/**
 *  LeetCode: 23. Merge k Sorted Lists (Hard)
 *
 *      You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 *      Merge all the linked-lists into one sorted linked-list and return it.
 *
 *
 *      Example :
 *          Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *          Output: [1,1,2,3,4,4,5,6]
 *          Explanation: The linked-lists are:
 *          [
 *            1->4->5,
 *            1->3->4,
 *            2->6
 *          ]
 *          merging them into one sorted list:
 *          1->1->2->3->4->4->5->6*
 *
 *          Input: lists = []
 *          Output: []*
 *
 *          Input: lists = [[]]
 *          Output: []*
 *
 *      Constraints:
 *          k == lists.length
 *          0 <= k <= 10^4
 *          0 <= lists[i].length <= 500
 *          -10^4 <= lists[i][j] <= 10^4
 *          lists[i] is sorted in ascending order.
 *          The sum of lists[i].length won't exceed 10^4.
 *
 *  Results:    AC (12 ms [99.79%]; 13 MB [88.15])
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
/* copy from 0021_Merge_Two_Sorted_Lists_Easy */
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
    while (l1 != NULL&& l2 != NULL) {
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


/*
 * Divide and Conquer approach is discussed.
 * This approach doesn’t require extra space for heap and works in O(nk Log k)
 * (It is known that merging of two linked lists can be done in O(n) time and O(n) space.)
 *
 * 1. The idea is to pair up K lists and merge each pair in linear time using O(n) space.
 * 2. After the first cycle, K/2 lists are left each of size 2*N.
 *    After the second cycle, K/4 lists are left each of size 4*N and so on.
 * 3. Repeat the procedure until we have only one list left.
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unsigned int i = 0, j = lists.size() - 1;

        if (lists.empty())
            return NULL;

        while (i < j) {
            lists[i] = mergeTwoLists(lists[i], lists[j]);

            i++;
            j--;

            if (i >= j)
                i = 0;
        }

        return lists[i];
    }
};
