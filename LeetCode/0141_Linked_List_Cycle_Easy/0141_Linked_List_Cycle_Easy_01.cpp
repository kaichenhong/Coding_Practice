/*
 *  Results:    AC (8 ms [96.26%];  10.4 MB [15.22%])
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> table;
        ListNode *ptr = head;

        while (ptr) {
            table.emplace(ptr);

            if (ptr->next && table.count(ptr->next))
                return true;

            ptr = ptr->next;
        }

        return false;
    }
};

