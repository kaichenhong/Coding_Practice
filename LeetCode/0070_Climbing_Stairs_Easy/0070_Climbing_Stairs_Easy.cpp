/**
 *  Results:    AC (0 ms [100.00%];  5.9 MB [81.57%])
 */


class Solution {
public:
    int climbStairs(int n) {
        int res = 0;

        // dfs(n, res);
        res = fibonacci(n);

        return res;
    }

private:
    int fibonacci_res(int n) {
        double root5 = sqrt(5);

        return (1 / root5) * (pow((1 + root5) / 2, n + 1) - pow((1 - root5) / 2, n + 1));
    }

    int fibonacci(int n) {
        int prev_prev = 1, prev = 1;

        if (n <= 1)
            return 1;

        for (int i = 2; i <= n; ++i) {
            int tmp = prev_prev + prev;
            prev_prev = prev;
            prev = tmp;
        }

        return prev;
    }

    void dfs(int n, int &res) {
        if (n < 0)
            return;

        if (n == 0) {
            res++;
            return;
        }

        for (int i = 1; i <= 2; ++i)
            dfs(n-i, res);
    }
};

