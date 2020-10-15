#include<vector>
/*
    Solution to the Remove Duplicates from Sorted Array problem
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        else {
            int i = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[i] != nums[j]) {
                    ++i;
                    nums[i] = nums[j];
                }
            }
            return i + 1;
        }
    }
};