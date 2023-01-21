/*
 *  Results:    AC (39 ms [83.72%];  89.4 MB [72.23%])
 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const size_t n = nums1.size(), m = nums2.size();

        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = n;

        while (l <= r) {
            const int cut1 = (l + r) / 2;
            const int cut2 = (n + m + 1) / 2 - cut1;
            const int l1 = (cut1 != 0) ? nums1.at(cut1 - 1) : INT_MIN;
            const int l2 = (cut2 != 0) ? nums2.at(cut2 - 1) : INT_MIN;
            const int r1 = (cut1 < n) ? nums1.at(cut1) : INT_MAX;
            const int r2 = (cut2 < m) ? nums2.at(cut2) : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
                return ((n + m) & 1U) ? max(l1, l2) : (double)(max(l1, l2) + min(r1, r2)) / 2;
            if (l1 > r2)
                r = cut1 - 1;
            else
                l = cut1 + 1;
        }

        return 0.0;
    }
};

