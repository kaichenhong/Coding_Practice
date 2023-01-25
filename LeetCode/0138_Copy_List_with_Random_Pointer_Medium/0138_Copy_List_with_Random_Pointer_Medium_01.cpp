/*
 *  Results:    AC (7 ms [86.50%];  11.3 MB [65.03%])
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head, *head_new = nullptr, *curr_ptr = nullptr;

        if (!iter)
            return head;

        while (__builtin_expect(!!(iter != nullptr), 1)) {
            Node *ptr = new Node(iter->val);
            mapping[iter] = ptr;

            if (__builtin_expect(!!(head_new == nullptr), 0)) {
                head_new = ptr;
                curr_ptr = ptr;
            } else {
                curr_ptr->next = ptr;
                curr_ptr = ptr;
            }

            iter = iter->next;
        }

        iter = head;
        curr_ptr = head_new;
        while (__builtin_expect(!!(iter != nullptr), 1)) {
            curr_ptr->random = mapping[iter->random];

            curr_ptr = curr_ptr->next;
            iter = iter->next;
        }

        return head_new;
    }

private:
    unordered_map<Node *, Node *> mapping;
};

