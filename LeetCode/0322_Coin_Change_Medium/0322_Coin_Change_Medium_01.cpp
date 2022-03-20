/*
 *  Results:    AC (752 ms [5.01%];  62.6 MB [7.17%])
 */


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;

        memo[0] = 0;
        return dfs(coins, amount, memo);
    }

private:
    int dfs(const vector<int> &coins, int target, unordered_map<int, int> &memo) {
        if (target < 0)
            return -1;
        if (memo.count(target))
            return memo[target];

        for (int i = 0; i < coins.size(); ++i) {
            int cur_res = dfs(coins, (target - coins[i]), memo);

            if (cur_res >= 0) {
                memo[target] = (memo[target] > 0)
                    ? std::min(memo[target], (cur_res + 1))
                    : (cur_res + 1);
            } else {
                memo[target] = (memo[target] > 0)
                    ? memo[target]
                    : -1;
            }

            //printf("i:%d, coins[i]:%d, target:%d, res:%d, memo[%d]:%d\n",
            //       i, coins[i], target, cur_res, target, memo[target]);
        }

        return memo[target];
    }
};

