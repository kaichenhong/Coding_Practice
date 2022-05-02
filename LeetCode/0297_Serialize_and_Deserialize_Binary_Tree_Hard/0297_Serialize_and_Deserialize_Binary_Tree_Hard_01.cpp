/*
 *  Results:    AC (46 ms [88.17%];  29.5 MB [72.70%])
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;

        if (root)
            q.push(root);
        while (!q.empty()) {
            TreeNode *ptr = q.front();

            q.pop();
            if (ptr) {
                out << ptr->val << " ";
                q.push(ptr->left);
                q.push(ptr->right);
            } else
                out << "null ";
        }

        // cout << out.str() << endl;
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in;
        string val;
        TreeNode *res = nullptr;
        queue<TreeNode*> q;

        if (data.empty())
            return res;

        in.str(data);
        in >> val;
        res = new TreeNode(stoi(val));
        q.push(res);
        while (!q.empty()) {
            TreeNode *ptr = q.front();

            q.pop();

            /* construct tree (left) */
            if (!(in >> val))
                break;

            if (val != "null") {
                TreeNode *node = new TreeNode(stoi(val));

                q.push(node);
                ptr->left = node;
            }

            /* construct tree (right) */
            if (!(in >> val))
                break;

            if (val != "null") {
                TreeNode *node = new TreeNode(stoi(val));

                q.push(node);
                ptr->right = node;
            }
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

