#include<unordered_map>
/*
    Solution to the Roman to Integer problem
    https://leetcode.com/problems/roman-to-integer/
*/

class Solution {
    std::unordered_map<char, int> to_int;
public:
    int romanToInt(std::string s) {
        int ret_val = 0;
        for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
            ret_val += this->to_int[*it];
            
            if (it != s.begin() && this->to_int[*(it - 1)] < this->to_int[*it]) {
                ret_val -= 2 * this->to_int[*(it - 1)];
            }
        }
        return ret_val;
    }
    
    Solution(): to_int({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}) {}
};