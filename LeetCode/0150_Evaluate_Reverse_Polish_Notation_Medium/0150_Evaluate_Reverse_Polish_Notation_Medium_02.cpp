/*
 *  Results:    AC (6 ms [95.43%];  12.0 MB [74.95%])
 */


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /* function object using lambda expression */
        op_map = {
            {"+", [](int a, int b){return a + b;}},
            {"-", [](int a, int b){return a - b;}},
            {"*", [](int a, int b){return a * b;}},
            {"/", [](int a, int b){return a / b;}}
        };

        for (const string &token : tokens) {
            const auto &op = op_map.find(token);

            if (op == op_map.end())
                val.push(stoi(token));
            else {
                const int rhs = val.top(); val.pop();
                const int lhs = val.top(); val.pop();

                val.push(op->second(lhs, rhs));
            }
        }
        return val.top();
    }

private:
    unordered_map<string, function<int (int, int)>> op_map;
    stack<int> val;
};

