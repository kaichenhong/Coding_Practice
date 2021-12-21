/*
 *  Results:    AC (4 ms [94.64%];  8.5 MB [81.90%])
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        queue<Node*> buf;

        if (!node)
            return NULL;

        map[node] = new Node(node->val);
        buf.push(node);
        while (!buf.empty()) {
            Node *ptr = buf.front();

            for (size_t i = 0; i < ptr->neighbors.size(); ++i) {
                if (map.count(ptr->neighbors[i]) == 0) {
                    map[ptr->neighbors[i]] = new Node(ptr->neighbors[i]->val);
                    buf.push(ptr->neighbors[i]);
                }

                map[ptr]->neighbors.push_back(map[ptr->neighbors[i]]);
            }

            buf.pop();
        }

        return map[node];
    }
};

