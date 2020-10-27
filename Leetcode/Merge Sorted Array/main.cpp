#include<vector>
/*
    Solution to the Merge Sorted Array problem
    https://leetcode.com/problems/merge-sorted-array/
*/
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        std::vector<int> tmp = std::vector<int>(nums1.begin(), nums1.begin() + m);
        while (i < m && j < n && k < nums1.size()) {
            if (tmp[i] < nums2[j]) {
                nums1[k] = tmp[i]; 
                ++i;
            }
            else {
                nums1[k] = nums2[j];
                ++j;
            }
            ++k;
        }
        
        while (i < m && k < nums1.size()) {
            nums1[k] = tmp[i];
            ++i;
            ++k;
        }
        
        while (j < n && k < nums1.size()) {
            nums1[k] = nums2[j];
            ++j;
            ++k;
        }
        
    }
};