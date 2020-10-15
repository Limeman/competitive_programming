#include<vector>
#include<string>
/*
    Solution to the Longest common prefix problem
    https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int min = INT_MAX;
        std::string shortest = "";
        for (auto s : strs) {
            if (s.length() < min) {
                min = s.length();
                shortest = s;
            }
        }
        
        if (min == 0) {
            return "";
        }
        int i = 0;
        bool all_match = false;
        for (; i < min; i++) {
            char c = strs[0][i];
            for (auto s : strs) {
                if (s[i] != c) {
                    goto done;
                }
            }
        }
        all_match = true;
        done:
        if (all_match) {
            return shortest;
        }
        else {
            return std::string(shortest.begin(), shortest.begin() + i);
        }
    }
};