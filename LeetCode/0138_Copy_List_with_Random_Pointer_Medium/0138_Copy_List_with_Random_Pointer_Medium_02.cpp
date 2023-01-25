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
        if (!head)
            return head;

        copy_and_merge_together(head);
        handle_random_part(head);
        return detach_merged_list(head);
    }

private:
    void copy_and_merge_together(Node *head) {
        Node *iter = head, *front;

        while (__builtin_expect(!!(iter != nullptr), 1)) {
            Node *ptr = new Node(iter->val);
            front = iter->next;
            iter->next = ptr;
            ptr->next = front;
            iter = front;
        }
    }

    void handle_random_part(Node *head) {
        Node *iter = head;

        while (__builtin_expect(!!(iter != nullptr), 1)) {
            if (iter->random != nullptr)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
    }

    Node * detach_merged_list(Node *head) {
        Node *iter = head, *head_new = nullptr, *front = nullptr;

        while (__builtin_expect(!!(iter != nullptr), 1)) {
            if (front == nullptr) {
                head_new = iter->next;
                front = iter->next;
            } else {
                front->next = iter->next;
                front = front->next;
            }
            iter->next = iter->next->next;
            iter = iter->next;
        }

        return head_new;
    }
};

