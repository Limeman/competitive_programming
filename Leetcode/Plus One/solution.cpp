#include<vector>

/*
    Solution to the Plus One problem
    https://leetcode.com/problems/plus-one/
*/

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int i = digits.size() - 1;
        for (; i >= 0; --i) {
            if (digits[i] != 9) {
                break;
            }
        }
        if (i < 0) {
            digits.insert(digits.begin(), 1);
            for (int i = 1; i < digits.size(); ++i) {
                digits[i] = 0;
            }
        }
        else if (i < digits.size() - 1){
            digits[i] += 1;
            for (int j = i + 1; j < digits.size(); ++j) {
                digits[j] = 0;
            }
        }
        else {
            digits[digits.size() - 1] += 1;
        }
        return digits;
    }
};