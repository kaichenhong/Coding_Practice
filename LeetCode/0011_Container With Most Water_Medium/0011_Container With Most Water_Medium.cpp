/**
 *  LeetCode: 11. Container With Most Water (Medium)
 *
 *     Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 *     Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * 
 *     Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *      Example:    1. [1,8,6,2,5,4,8,3,7] => 49;
 *
 *
 *  Results:    AC (16 ms [95.47%];  9.8 MB [72.17%])
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        if (height.size() == 1)
            return height[0];

        auto l_ptr = height.begin(), r_ptr = height.end()-1;
        int areaMax = 0;
        /**
         * Two pointers, move one pointer at once.
         * 
         * Because width is the same (when choosing move l_ptr or r_ptr), 
         *  choose the bigger value of the pointer and move the pointer of the little one. 
         */
        while (l_ptr < r_ptr) {
            int width = int(r_ptr - l_ptr), boundary = 0;
            if (*l_ptr > *r_ptr) {
                boundary = *r_ptr;
                r_ptr--;
            }
            else {
                boundary = *l_ptr;
                l_ptr++;
            }
            areaMax = std::max(boundary * width, areaMax);
        }

        return areaMax;
    }
};