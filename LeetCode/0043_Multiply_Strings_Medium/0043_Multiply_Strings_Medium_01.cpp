/*
 *  Results:    AC (3 ms [96.44%];  6.6 MB [73.15%])
 */


class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> nums(num1.size() + num2.size(), 0);
        unsigned int skip_leading_zero = 0;
        string ans = "";

        if (num1 == "0" || num2 == "0")
            return "0";

        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                nums.at(i+j+1) += (num1.at(i) - '0') * (num2.at(j) - '0');
                nums.at(i+j) += nums.at(i+j+1) / 10;
                nums.at(i+j+1) %= 10;
            }
        }

        while (skip_leading_zero < nums.size() && nums.at(skip_leading_zero) == 0)
            ++skip_leading_zero;
        for (int i = skip_leading_zero; i < nums.size(); ++i)
            ans.push_back(nums.at(i) + '0');

        return ans;
    }
};
/*
012345
======
   123
   456
------
    18
   12
   6
   15
  10
  5
  12
  8
 4
------
 56088
*/

