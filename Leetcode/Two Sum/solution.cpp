#include<unordered_map>
#include<vector>
/*
    Solution to the two sum problem
    https://leetcode.com/problems/two-sum/
*/
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // If the complement already exsists, return it
            std::unordered_map<int, int>::iterator it = hash.find(complement);
            if (it != hash.end() && it->second != i) {
                return std::vector<int>({i, it->second});
            }
            hash.emplace(nums[i], i);
        }
        
        return std::vector<int>({-1, -1});            
    }
};