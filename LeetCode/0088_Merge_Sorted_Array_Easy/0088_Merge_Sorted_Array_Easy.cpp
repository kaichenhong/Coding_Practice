/**
 *  LeetCode: 88. Merge Sorted Array (Easy)
 *
 *      Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 *      Note:
 *
 *         The number of elements initialized in nums1 and nums2 are m and n respectively.
 *         You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 *
 *
 *      Example:    nums1 = [1,2,3,0,0,0], m = 3
 *                  nums2 = [2,5,6],       n = 3
 *                  Output: [1,2,2,3,5,6]
 *
 *
 *
 *  Results:    AC (0 ms [100.00%];   8.6 MB [93.48%])
 */


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)   return;
        if (m == 0) {
            nums1 = nums2;
            return;
        } 
        
        // three pointer, one for store sorted value from rear of nums1, others for choose the biggest values to store.
        int mIdx = m-1, nIdx = n-1, storeIdx = m+n-1;
        for (storeIdx; storeIdx >= 0; --storeIdx) {
            if (mIdx >= 0 && nIdx >=0) {
                if (nums1[mIdx] >= nums2[nIdx]) {
                    nums1[storeIdx] = nums1[mIdx--];
                }
                else {
                    nums1[storeIdx] = nums2[nIdx--];
                }
            }
            else {
                if (mIdx >= 0) {
                    nums1[storeIdx] = nums1[mIdx--];
                }
                else {
                    nums1[storeIdx] = nums2[nIdx--];
                }
            }
        }
    }
};