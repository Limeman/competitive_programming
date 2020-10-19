#include<string>

/*
    Solution to the Length of Last Word problem
    https://leetcode.com/problems/length-of-last-word/
*/

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.length() - 1, pos = 0;
        bool last_started = false;
        for (; i >= 0; --i) {
            if (s[i] != ' ' && !last_started) {
                last_started = true;
                pos = i;
            }
            if (s[i] == ' ' && last_started) {
                break;
            }
        }
        if (i < 0 && !last_started) {
            return pos;
        }
        else if (i < 0 && last_started) {
            return pos + 1;
        }
        else {
            return pos - i;
        }
    }
};