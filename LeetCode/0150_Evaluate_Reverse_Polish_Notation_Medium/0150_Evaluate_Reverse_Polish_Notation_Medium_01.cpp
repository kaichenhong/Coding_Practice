/*
 *  Results:    AC (7 ms [94.29%];  11.9 MB [92.90%])
 */


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (const string &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/")
                calc_result_by_op_and_push(s);
            else
                val.push(stoi(s));
        }
        return val.top();
    }

private:
    void calc_result_by_op_and_push(const string &op) {
        int v1, v2, result;

        v2 = val.top();
        val.pop();
        v1 = val.top();
        val.pop();
        if (op == "+")
            result = v1 + v2;
        if (op == "-")
            result = v1 - v2;
        if (op == "*")
            result = v1 * v2;
        if (op == "/")
            result = v1 / v2;
        val.push(result);
    }

    stack<int> val;
};

