/*
 *  Results:    AC (16 ms [97.93%];  24.0 MB [56.41%])
 */


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int buf;
        vector<int> results(nums.size());

        buf = 1;
        for (int i = 0; i < nums.size(); ++i) {
            buf *= nums[i];
            results[i] = buf;
        }

        buf = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            /* calculate result simultaneously */
            if (i == 0)
                results[i] = buf;
            else if (i == nums.size()-1)
                results[i] = results[i-1];
            else
                results[i] = results[i-1] * buf;

            buf *= nums[i];
        }

        return results;
    }
};


/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int buf;
        vector<int> product_l(nums.size(), 1), product_r(nums.size(), 1);
        vector<int> results(nums.size());

        buf = 1;
        for (int i = 0; i < nums.size(); ++i) {
            buf *= nums[i];
            product_l[i] = buf;
        }

        buf = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            buf *= nums[i];
            product_r[i] = buf;
        }

        for (int i = 0; i < nums.size(); ++i) {
            //printf("[i:%d] product: l:%d, r:%d\n", i, product_l[i], product_r[i]);
            if (i == 0)
                results[i] = product_r[i+1];
            else if (i == nums.size()-1)
                results[i] = product_l[i-1];
            else
                results[i] = product_l[i-1] * product_r[i+1];
        }

        return results;
    }
};
*/

