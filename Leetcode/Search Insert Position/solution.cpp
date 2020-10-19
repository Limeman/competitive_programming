#include<vector>

/*
    Solution to the Search Insert Position problem
    https://leetcode.com/problems/search-insert-position/
*/

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums[0] > target) {
            return 0;
        }
        else if (nums[nums.size() - 1] < target) {
            return nums.size();
        }
        else {
            return binary_search(nums, 0, nums.size() - 1, target);
        }
    }
    
    int binary_search(std::vector<int>& nums, int lower, int upper, int target) {
        if (upper >= lower) {
            int mid = (upper + lower) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                return binary_search(nums, lower, mid - 1, target);
            }
            else {
                return binary_search(nums, mid + 1, upper, target);
            }
            
        }
        else {
            return lower;
        }
    }
};