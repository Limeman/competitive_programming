#include<vector>

/*
    Solution to the Maximum Subarray problem
    https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
    int max(int a, int b) {
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
    
    int divide_and_conquer(std::vector<int>& nums, int lower, int upper) {
        if (lower == upper) {
            return nums[lower];
        }
        else {
            int mid = (lower + upper) / 2;
            
            int left = divide_and_conquer(nums, lower, mid);
            int right = divide_and_conquer(nums, mid + 1, upper);
            int current = max_part_sum(nums, lower, upper);
            
            if (current > left && current > right) {
                return current;
            }
            else if (left > right) {
                return left;
            }
            else {
                return right;
            }
        }
    }
    
    int max_sum(std::vector<int>& nums, int lower, int upper, int mid) {
        int left = max_part_sum(nums, lower, mid);
        int right =  max_part_sum(nums, mid + 1, upper);
        
        if (left + right > left && left + right > right) {
            return left + right;
        }
        else if (left > right) {
            return left;
        }
        else {
            return right;
        }
    }
    
    int max_part_sum(std::vector<int>& nums, int lower, int upper) {
        int sum = 0, ret_val = INT_MIN;
        
        for (int i = lower; i <= upper; ++i) {
            sum = max(nums[i], sum + nums[i]);
            
            if (sum > ret_val) {
                ret_val = sum;
            }
        }
        
        return ret_val;
    }
public:
    
    
    int maxSubArray(std::vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums[0];
        }
        else {
            return divide_and_conquer(nums, 0, nums.size() - 1);
        }
        
        
    }
    
    
    
};