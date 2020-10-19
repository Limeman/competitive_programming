#include<string>

/*
    Solution to the Count and Say problem
    https://leetcode.com/problems/count-and-say/
*/

class Solution {
public:
    std::string countAndSay(int n) {
        std::string prev = "", current = "1";
        for (int i = 0; i < n - 1; ++i) {
            prev = current;
            current = "";
            int k = 0;
            for (int j = 0; j < prev.length(); ++j) {
                if (prev[j] != prev[k]) {
                    current += std::to_string(j - k) + prev[k];
                    k = j;
                }
            }
            current += std::to_string(prev.length() - k) + prev[k];
        }
        return current;
    }
};