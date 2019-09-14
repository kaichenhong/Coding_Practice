/**
 *  LeetCode: 575. Distribute Candiess (Easy)
 *
 *      Given an integer array with even length, where different numbers in this array represent different kinds of candies. 
 *      Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. 
 *      Return the maximum number of kinds of candies the sister could gain. 
 *
 *          The length of the given array is in range [2, 10,000], and will be even.
 *          The number in given array is in range [-100,000, 100,000].
 *
 *
 *      Example:    1. candies = [1,1,2,2,3,3] => 3.
 *                      There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
 *                      Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
 *                      The sister has three different kinds of candies. 
 *
 *                  2. candies = [1,1,2,3] => 2.
 *                      For example, the sister has candies [2,3] and the brother has candies [1,1]. 
 *                      The sister has two different kinds of candies, the brother has only one kind of candies. 
 *
 *
 *
 *  Results:    AC (60 ms [99.81%];  16.1 MB [100.00%])
 *              AC (144 ms [98.64%];  38.2 MB [66.67%])
 */


class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        // speed up cin/cout.
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int cnt = 0;
        /*unordered_map<int, int> categories;
        for (size_t i = 0; i < candies.size() && cnt < (candies.size() >> 1); ++i) {
            if (categories.find(candies[i]) == categories.end()) {
                categories[candies[i]] = i;
                cnt++;
            }
        }*/

        bitset<200001> categories;  // range [-100,000, 100,000] => 200001
        for (size_t i = 0; i < candies.size() && cnt < (candies.size() >> 1); ++i) {
            if (categories[100000+candies[i]] == 0) {
                categories[100000+candies[i]] = 1;
                cnt++;
            }
        }

        return cnt;
    }
};