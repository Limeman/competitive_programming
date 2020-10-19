#include<vector>

/*
    Solution to Remove Element Problem from¨
    https://leetcode.com/problems/remove-element/
*/

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int size = nums.size();
        if (size == 0) {
            return 0;
            
        }
        else if (size == 1) {
            if (nums[0] == val) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else {
            int i = 0;
            for (int j = 1; j < size; ++j) {
                if (nums[i] != val) {
                        ++i;
                }
                if (nums[i] == val) {
                    nums[i] = nums[j];
                    nums[j] = val;
                }
            }
            if (nums[i] != val) {
                return i + 1;
            }
            else {
                return i;
            }
        }
    }
};