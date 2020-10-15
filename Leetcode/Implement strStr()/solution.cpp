#include<string>
/*
    Solution to the Implement strStr() problem
    https://leetcode.com/problems/implement-strstr/
*/

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int needle_len = needle.length(), haystack_len = haystack.length();
        
        if (haystack == needle) {
            return 0;
        }
        else {
            for (int i = 0; i <= haystack_len - needle_len; ++i) {
                if (std::string(std::string(haystack, i, needle_len)) == needle) {
                    return i;
                }
            }
            return -1;
        }
    }
};